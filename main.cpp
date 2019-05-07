//---------------------------------------------------------------------------//
// Application console Library Management
// Compiler: GNU C++, MSVS C++
//---------------------------------------------------------------------------//

#include "manage_library.h"

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