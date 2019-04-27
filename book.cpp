#include "book.h"

// Ham khoi tao khong tham so
Book::Book()
{
  strcpy(book_id_, "");
  strcpy(book_title_, "");
  strcpy(publisher_, "");
  strcpy(author_, "");
  strcpy(type_, "");
  year_ = 0;
  amount_ = 0;
}

// Ham khoi tao co tham so
Book::Book(char *book_id, char *book_title, unsigned short year,
           char *publisher, char *author, char *type, int amount)
{
  *book_id_ = *book_id;
  *book_title_ = *book_title;
  year_ = year;
  *publisher_ = *publisher;
  *author_ = *author;
  *type_ = *type;
  amount_ = amount;
}

// Ham huy
Book::~Book() {}

//------------------------------------------------------------------//

// Gan gia tri cho ma sach
void Book::set_book_id(string book_id) { strcpy(book_id_, book_id.c_str()); }

// Tra ve ma sach
string Book::get_book_id() { return book_id_; }

// Gan gia tri cho ten sach
void Book::set_book_title(string book_title)
{
  strcpy(book_title_, book_title.c_str());
}

// Tra ve ten sach
string Book::get_book_title() { return book_title_; }

// Gan gia tri cho nam xuat ban cua sach
void Book::set_year(unsigned short year) { year_ = year; }

// tra ve nam xuat ban cua sach
unsigned short Book::get_year() { return year_; }

// Gan gia tri cho nha xuat ban
void Book::set_publisher(string publisher)
{
  strcpy(publisher_, publisher.c_str());
}

// Tra ve ten nha xuat ban
string Book::get_publisher() { return publisher_; }

// Gan gia tri cho ten tac gia
void Book::set_author(string author) { strcpy(author_, author.c_str()); }

// Tra ve ten tac gia
string Book::get_author() { return author_; }

// Gan gia tri cho loai sach
void Book::set_type(string type) { strcpy(type_, type.c_str()); }

// Tra ve loai sach
string Book::get_type() { return type_; }

// Gan gia tri cho so luong sach
void Book::set_amount(int amount) { amount_ = amount; }

// Tra ve so luong sach
int Book::get_amount() { return amount_; }

//------------------------------------------------------------------//

// Nhap thong tin sach
void Book::input_an_info()
{

  bool check = true; // Gia tri kiem tra nhap dung/sai

  // Dong thong bao khi nhap sai
  char str_error[] = "\n Nhap sai, vui long nhap lai!\n\n";

  cin.ignore();

  // Nhap Ma sach
  do
  {
    check = true;
    try
    {
      cout << " Ma sach (6 so): ";
      cin.getline(book_id_, LENGTH_BOOK_ID);
      if (strlen(book_id_) != LENGTH_BOOK_ID - 1 || cin.fail())
        throw str_error;
      else
      {
        for (unsigned int i = 0; i < strlen(book_id_); i++)
        {
          if (!isdigit(book_id_[i]))
            throw str_error;
        }
      }

      //-------------Kiem tra Ma sach da ton tai chua------------------//
      ifstream in_file;
      Book book;
      in_file.open(BOOK_FILE, ios::app | ios::binary);
      if (!in_file)
        throw "\n  Loi mo file\n";

      // Doc thong tin sach cho den het file (khong doc duoc nua)
      while (in_file.read(reinterpret_cast<char *>(&book), sizeof(book)))
      {
        if (book.get_book_id() == book_id_)
        {
          in_file.close();
          throw "\n Ma sach da ton tai!\n\n";
        }
      }
      in_file.close();
      //---------------------------------------------------------------//
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap Ten sach
  do
  {
    check = true;
    cout << " Ten sach: ";
    cin.getline(book_title_, LENGTH_BOOK_TITLE);
    try
    {
      if (cin.fail())
        throw str_error;
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap nam xuat ban
  do
  {
    check = true;
    cout << " Nam xuat ban: ";
    cin >> year_;
    try
    {
      if (year_ <= 1900 || cin.fail())
        throw str_error;
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  cin.ignore();

  // Nhap nha xuat ban
  do
  {
    check = true;
    cout << " Nha xuat ban: ";
    cin.getline(publisher_, LENGTH_PUBLISHER);
    try
    {
      if (cin.fail())
        throw str_error;
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!check);

  // Nhap ten tac gia
  do
  {
    check = true;
    cout << " Ten tac gia: ";
    cin.getline(author_, LENGTH_AUTHOR);
    try
    {
      if (cin.fail() || !check_string(this->get_author()))
        throw str_error;
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap the loai sach
  do
  {
    check = true;
    cout << " The loai sach: ";
    cin.getline(type_, LENGTH_TYPE);
    try
    {
      if (cin.fail() || !check_string(this->get_type()))
        throw str_error;
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);

  // Nhap so luong sach
  do
  {
    check = true;
    cout << " So luong: ";
    cin >> amount_;
    try
    {
      if (year_ < 0 || cin.fail())
        throw str_error;
    }
    catch (const char *str)
    {
      cerr << str;
      check = false;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  } while (!check);
}

// Hien thi thong tin sach
void Book::display_book_info(int i)
{
  cout << " ";
  cout << " " << setw(5) << left << i;
  cout << " " << setw(9) << left << book_id_;
  cout << " " << setw(30) << left << book_title_;
  cout << " " << setw(8) << left << year_;
  cout << " " << setw(24) << left << publisher_;
  cout << " " << setw(24) << left << author_;
  cout << " " << setw(14) << left << type_;
  cout << " " << setw(5) << left << amount_;
  cout << endl;
}

// Hien thi danh sach sach
void Book::display_book_list(list<Book> books)
{
  list<Book>::iterator it;
  int i = 0;
  for (it = books.begin(); it != books.end(); it++)
  {
    i++;
    // Hien thi thong tin sach
    it->display_book_info(i);
  }
}

// Hien thi tieu de cot danh sach sach
void Book::title_books_list()
{
  cout << " ";
  cout << setw(6) << left << "| STT ";
  cout << setw(10) << left << "| Ma sach ";
  cout << setw(31) << left << "| Ten sach ";
  cout << setw(9) << left << "| Nam XB ";
  cout << setw(25) << left << "| Nha xuat ban ";
  cout << setw(25) << left << "| Tac gia ";
  cout << setw(15) << left << "| The loai ";
  cout << setw(6) << left << "| SL |";
  cout << endl;
}

// Kiem tra chuoi co chua ky tu khong phai chu (so hoac ky tu dac biet)
// Tra ve True khi chuoi chi co ky tu chu
// Tra ve false khi chuoi co ky tu khac ky tu chu
bool Book::check_string(string str)
{
  bool check = true;
  for (unsigned int i = 0; i < str.length(); i++)
  {
    if (str[i] < 32 || (str[i] > 32 && str[i] < 65) ||
        (str[i] > 90 && str[i] < 97) || str[i] > 122)
    {
      check = false;
      cin.clear();
      break;
    }
  }
  return check;
}