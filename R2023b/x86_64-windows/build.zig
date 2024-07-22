const std: type = @import("std");
const builtin: type = @import("builtin");
const Dir: type = std.fs.Dir;
const Walker: type = Dir.Walker;
const LazyPath: type = std.Build.LazyPath;
const ResolvedTarget: type = std.Build.ResolvedTarget;
const OptimizeMode: type = std.builtin.OptimizeMode;
const InstallArtifact: type = std.Build.Step.InstallArtifact;
const InstallFile: type = std.Build.Step.InstallFile;
const Run: type = std.Build.Step.Run;
const Compile: type = std.Build.Step.Compile;
const Query: type = std.Target.Query;
const Allocator: type = std.mem.Allocator;
const Tag: type = std.Target.Os.Tag;

pub fn build(b: *std.Build) !void {
    const opt: OptimizeMode = b.standardOptimizeOption(.{});
    const querys: []const Query = &.{
        .{ .cpu_arch = .x86_64, .os_tag = .windows, .abi = .gnu },
        //.{ .cpu_arch = .x86_64, .os_tag = .linux, .abi = .gnu },
    };
    const model_name: []const u8 = "default_model";
    for (querys) |query| {
        const target: ResolvedTarget = b.resolveTargetQuery(query);
        //const target_os: Tag = target.result.os.tag;
        const mex: *Compile = b.addSharedLibrary(.{
            .name = model_name,
            .target = target,
            .optimize = opt,
            .link_libc = true,
            .pic = true,
        });
        const matlab: LazyPath = LazyPath{ .cwd_relative = "C:/Program Files/MATLAB/R2023b" };
        mex.addIncludePath(matlab.path(b, "extern/include"));
        mex.addIncludePath(matlab.path(b, "simulink/include"));
        mex.addIncludePath(matlab.path(b, "rtw/c/src"));
        mex.addIncludePath(b.path("."));
        mex.addLibraryPath(matlab.path(b, "extern/lib/win64/mingw64"));
        mex.linkSystemLibrary("libmx");
        mex.linkSystemLibrary("libmex");
        mex.linkSystemLibrary("libmat");
        mex.linkSystemLibrary("libut");
        mex.linkSystemLibrary("m");
        mex.linkSystemLibrary("libfixedpoint");
        mex.addCSourceFiles(.{
            .files = &.{
                "default_model_sf.c",
                //"rt_nonfinite.c",
            },
            .flags = &.{
                "-DTID01EQ=0",
                "-DMODEL=default_model",
                "-DNUMST=1",
                "-DNCSTATES=0",
                "-DMAT_FILE=0",
                "-DINTEGER_CODE=0",
                "-DONESTEPFCN=0",
                "-DTERMFCN=1",
                "-DMULTI_INSTANCE_CODE=0",
                "-DCLASSIC_INTERFACE=1",
                "-DALLOCATIONFCN=0",
                "-D_CRT_SECURE_NO_WARNINGS",
                "-DHAVESTDIO",
                "-DMDL_REF_SIM_TGT=1",
                "-DMT=0",
                "-DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0",
                "-DMATLAB_MEX_FILE",
            },
        });
        const install_mex = b.addInstallArtifact(mex, .{ .dest_sub_path = "default_model_sf.mexw64" });
        b.getInstallStep().dependOn(&install_mex.step);
    }
}
