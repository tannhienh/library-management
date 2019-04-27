//---------------------------------------------------------------------------//
// Application console Manage Library
// Compiler: g++, MSVS
//---------------------------------------------------------------------------//

#include "manage_borrow.h"

//====================================================//
// HAM MAIN
//====================================================//
int main()
{
  try
  {
    main_menu(); // Thuc hien lua chon menu chinh
  }
  catch (exception &e)
  {
    // Bat loi neu co bat cu loi nao
    cerr << "\nLoi: " << e.what() << endl;
  }
  catch (...)
  {
    cerr << "\nLoi ngoai le!\n";
  }

  cin.get();
  return 0;
}
//====================================================//