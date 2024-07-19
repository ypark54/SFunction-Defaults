{
  {
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);
    ssSetChecksumVal(rts, 0, 2621093173U);
    ssSetChecksumVal(rts, 1, 745605684U);
    ssSetChecksumVal(rts, 2, 1729767543U);
    ssSetChecksumVal(rts, 3, 2475002188U);
  }
}
