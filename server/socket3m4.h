



/* This file was automatically generated from m4/socket3.m4, do not edit! */


































  case order_FindFunction:
    switch (n) {
      case 2: L = a[1]._; break;
      case 4: L = a[3]._; break;
    }
    break;










  case order_AttachHW:
    switch (n) {
      case 2: L = a[1]._; break;
    }
    break;
  case order_DetachHW:
    switch (n) {
      case 2: L = a[1]._; break;
    }
    break;

  case order_SetFontTranslation:
    switch (n) {
      case 1: L = 0x80; break;
    }
    break;
  case order_SetUniFontTranslation:
    switch (n) {
      case 1: L = 0x80; break;
    }
    break;












  case order_ExposeWidget:
    switch (n) {
      case 6: L = a[2]._*a[3]._; break;
      case 7: L = a[2]._*a[3]._; break;
      case 8: L = a[2]._*a[3]._; break;
    }
    break;






  case order_RestackChildrenWidget:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;



  case order_CreateGadget:
    switch (n) {
      case 4: L = a[2]._*a[3]._; break;
    }
    break;

  case order_CreateButtonGadget:
    switch (n) {
      case 4: L = a[2]._*a[3]._; break;
    }
    break;

  case order_WriteTextsGadget:
    switch (n) {
      case 5: L = a[2]._*a[3]._; break;
    }
    break;
  case order_WriteHWFontsGadget:
    switch (n) {
      case 5: L = a[2]._*a[3]._; break;
    }
    break;

  case order_CreateWindow:
    switch (n) {
      case 2: L = a[1]._; break;
      case 3: L = a[1]._; break;
    }
    break;


  case order_WriteAsciiWindow:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;
  case order_WriteStringWindow:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;
  case order_WriteHWFontWindow:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;
  case order_WriteHWAttrWindow:
    switch (n) {
      case 5: L = a[4]._; break;
    }
    break;














  case order_Create4MenuRow:
    switch (n) {
      case 5: L = a[4]._; break;
    }
    break;



  case order_RestackChildrenRow:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break; 


  case order_Create4MenuMenuItem:
    switch (n) {
      case 5: L = a[4]._; break;
    }
    break;



  case order_SetInfoMenu:
    switch (n) {
      case 4: L = a[3]._; break;
      case 5: L = a[3]._; break;
    }
    break;

  case order_CreateMsgPort:
    switch (n) {
      case 2: L = a[1]._; break;
    }
    break;
  case order_FindMsgPort:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;

  case order_BgImageScreen:
    switch (n) {
      case 4: L = a[2]._*a[3]._; break;
    }
    break;



























  case order_SendToMsgPort:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;
  case order_BlindSendToMsgPort:
    switch (n) {
      case 3: L = a[2]._; break;
    }
    break;




  case order_NotifySelection:
    switch (n) {
      case 4: L = TW_MAX_MIMELEN; break;
      case 6: L = a[5]._; break;
    }
    break;





