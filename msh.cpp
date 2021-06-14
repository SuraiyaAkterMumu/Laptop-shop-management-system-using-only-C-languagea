#include<bits/stdc++.h>
#include<iomanip> ///setw(int)// Sets the field width to be used on output operations.
#include<windows.h>
using namespace std;

class Admin;
class Customer;
vector<Admin>v;

class coordinate
{
public:
    COORD coord;
    coordinate()
    {
        coord = {0,0};
    }
    void gotoxy(int x,int y)
    {
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
};

class ShopName : public coordinate
{
public:
    void Dragors()
    {
        coordinate c;
        c.gotoxy(25,2);
        printf("********************************");
        c.gotoxy(25,3);
        printf("*                              *");
        c.gotoxy(25,4);
        printf("*                              *");
        c.gotoxy(25,5);
        printf("*                              *");
        c.gotoxy(25,6);
        printf("*        Dragors Shop Ltd.     *");
        c.gotoxy(25,7);
        printf("*                              *");
        c.gotoxy(25,8);
        printf("*                              *");
        c.gotoxy(25,9);
        printf("*                              *");
        c.gotoxy(25,10);
        printf("********************************");
    }
};

class Menu : public ShopName
{
public:
    void ShowMenu()
    {
        system("cls");
        ShopName b;
        b.Dragors();
        coordinate c;
        c.gotoxy(25,12);
        printf("*****************************************");
        c.gotoxy(25,13);
        printf("*                                       *");
        c.gotoxy(25,14);
        printf("*   1. Add Products Information         *");
        c.gotoxy(25,15);
        printf("*                                       *");
        c.gotoxy(25,16);
        printf("*   2. List of Products Information     *");
        c.gotoxy(25,17);
        printf("*                                       *");
        c.gotoxy(25,18);
        printf("*   3. Modify Product Records           *");
        c.gotoxy(25,19);
        printf("*                                       *");
        c.gotoxy(25,20);
        printf("*   4. Delete Product Record            *");
        c.gotoxy(25,21);
        printf("*                                       *");
        c.gotoxy(25,22);
        printf("*   5. View Individual Product          *");
        c.gotoxy(25,23);
        printf("*                                       *");
        c.gotoxy(25,24);
        printf("*   6. Display Sorted Products Record   *");
        c.gotoxy(25,25);
        printf("*                                       *");
        c.gotoxy(25,26);
        printf("*   7. Display Customer List            *");
        c.gotoxy(25,27);
        printf("*                                       *");
        c.gotoxy(25,28);
        printf("*   8. Exit                             *");
        c.gotoxy(25,29);
        printf("*                                       *");
        c.gotoxy(25,30);
        printf("*****************************************");
        c.gotoxy(25,34);
        printf("What would you like to do?  ");
    }
};

int Product_serial_Number()
{
    int ID;
    ifstream fin("ProductNumber.txt");
    fin>>ID;
    ID = ID + 1;
    ofstream fout("ProductNumber.txt");
    fout<<ID;
    return ID;
}

string Product_Price(string id)
{
    ifstream fin("Productlist.txt");
    string line;
    string  n;
    while(getline(fin,line))
    {
        stringstream sin(line);
        string id_;
        string dummy;
        getline(sin, id_, ',');

        if(id_ == id)
        {
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            sin>>n;
            return n;
            break;
        }

    }
}

void Modify_Menu()
{
    printf("\n\n\t\tWhat would you like to modify?");
    printf("\n\n");
    printf("\n\t\t\t1.Brand");
    printf("\n\t\t\t2.Processor");
    printf("\n\t\t\t3.Ram");
    printf("\n\t\t\t4.Rom");
    printf("\n\t\t\t5.Generation");
    printf("\n\t\t\t6.Date of store");
    printf("\n\t\t\t7.Price");
    printf("\n\t\t\t8.Item");

    printf("\n\n\n");
}

class Product
{
protected:
    int ID,Item;
    string Brand,Ram,Rom,Processor,Generation,Date_of_store,price ;
public:
    virtual void ShowList()=0;
};

class Customer: public Product,public ShopName
{
    int P_id;
    string name,Phone_no;
public:
    void ShowList()
    {
        system("cls");
        ShopName b;
        b.Dragors();
        cout<<endl<<endl<<endl<<endl;
        cout<<"  ID  |       Brand        |  Processor      |       Ram        |       Rom     |      Price      |   Current Item  "<<endl<<endl;
        ifstream fin("ProductList.txt");
        string line;
        int n,i;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string dummy;
            getline(sin, dummy, ',');
            cout<<setw(2)<<" "<<dummy<<" | ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(17)<<left<<dummy<<" |  ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(13)<<left<<dummy<<" |  ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(14)<<left<<dummy<<" |  ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(11)<<left<<dummy<<" |  ";
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            cout<<" "<<setw(13)<<left<<dummy<<" | ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(9)<<left<<dummy<<endl;


        }
        cout<<endl<<endl;
           cout<<"                         Press any key to continue!!"<<endl;
//        printf("\n                         1.Buy Item\n");
//            printf("                         2.exit\n");
//            printf("\t\t  Enter Your choice.... \n\n");
        getchar();
        getchar();

    }
    int Buy_product(string id)
    {
        system("cls");
        ShopName b;
        b.Dragors();
        coordinate c;
        ifstream fin("Productlist.txt");
        string line;
        string  n;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string id_;
            string dummy;
            getline(sin, id_, ',');

            if(id_ == id)
            {
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');
                getline(sin, dummy, ',');

                if(stoi(dummy) == 0)
                {
                    c.gotoxy(28,17);
                    cout<<"out of stock!!! "<<endl;
                    c.gotoxy(28,19);
                    cout<<"press any key to go back!!"<<endl;
                    getchar();
                    getchar();
                    return 0;

                }
                else
                {
                    ofstream fout("CustomerList.txt",fstream :: app);

                    cin.ignore();
                    c.gotoxy(28,17);
                    cout<<"Enter Your Name : ";
                    cin>>name;
                    cin.ignore();
                    c.gotoxy(28,19);
                    cout<<"Enter Your Phone Number : ";
                    cin>>Phone_no;
                    fout<<id<<","<<name<<","<<Phone_no<<endl;

                    cout<<"\n\n\t\tSuccessfully Have Brought the Product !!!!"<<endl;
                    cout<<"Press any key to GO BACK..!!"<<endl;
                    getchar();
                    getchar();
                    return 1;

                }

            }

        }
//        ofstream fout("CustomerList.txt",fstream :: app);
//
//        cin.ignore();
//        c.gotoxy(28,17);
//        cout<<"Enter Your Name : ";
//        cin>>name;
//        cin.ignore();
//        c.gotoxy(28,19);
//        cout<<"Enter Your Phone Number : ";
//        cin>>Phone_no;
//        fout<<id<<","<<name<<","<<Phone_no<<endl;
//
//        cout<<"\n\n\t\tSuccessfully Have Brought the Product !!!!"<<endl;
    }
    void Updateitem(string  id)
    {

        ifstream fin("ProductList.txt");
        ofstream fout("temp.txt", fstream :: app);
        string line, dummy;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string id_;
            getline(sin, id_,',');
            if(id == id_)
            {
                fout<<id_<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');

                fout<<stoi(dummy)-1<<endl;


            }

            else
            {
                fout<<id_<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<endl;
            }
        }

        fin.close();
        fout.close();

        remove("ProductList.txt");
        rename("temp.txt","ProductList.txt");
    }



};

class  Admin : public ShopName,public Product
{

public:
    void setID(int n)
    {
        ID = n;
    }
    void setBrand(string Brand_)
    {
        Brand = Brand_;
    }

    void setRam(string Ram_)
    {
        Ram = Ram_;
    }

    void setRom(string Rom_)
    {
        Rom = Rom_;
    }

    void setProcessor(string Processor_)
    {
        Processor = Processor_;
    }

    void setGeneration(string Generation_)
    {
        Generation = Generation_;
    }

    void setDate_of_store(string Date_of_store_)
    {
        Date_of_store = Date_of_store_;
    }

    void setPrice(string price_)
    {
        price = price_;
    }
    void setItem(int Item_)
    {
        Item=Item_;
    }



    void InputInformation()
    {
        system("cls");
        ShopName b;
        b.Dragors();
        coordinate c;
        ofstream fout("ProductList.txt",fstream :: app);
        ID =Product_serial_Number();
        cin.ignore();
        c.gotoxy(28,15);
        cout<<"Product serial Number           : "<<ID<<endl;

        string s,i;
        int n;

        c.gotoxy(28, 17);
        cout<<"Enter Brand                     : ";
        getline(cin,s);
        cout<<endl;
        setBrand(s);
        c.gotoxy(28, 19);
        cout<<"Enter Date of store(DD/MM/YYYY) : ";
        cin>>s;
        cout<<endl;
        setDate_of_store(s);
        cin.ignore();
        c.gotoxy(28, 21);
        cout<<"Enter Ram                       : ";
        getline(cin,s);
        cout<<endl;
        setRam(s);
        c.gotoxy(28, 23);
        cout<<"Enter Rom                       : ";
        getline(cin,s);
        cout<<endl;
        setRom(s);
        c.gotoxy(28, 25);
        cout<<"Enter Processor                 : ";
        cin>>s;
        cout<<endl;
        setProcessor(s);
        cin.ignore();
        c.gotoxy(28, 27);
        cout<<"Enter Generation                : ";
        cin>>s;
        cout<<endl;
        setGeneration(s);
        cin.ignore();
        c.gotoxy(28, 29);
        cout<<"Enter Items                     : ";
        cin>>n;
        cout<<endl;
        setItem(n);
        cin.ignore();
        c.gotoxy(28, 31);
        cout<<"Enter Price (in Dollar)         : ";
        cin>>i;
        cout<<endl;
        setPrice(i);
        cin.ignore();
        fout<<ID<<","<<Brand<<","<<Processor<<","<<Ram<<","<<Rom<<","<<Generation<<","<<Date_of_store<<","<<price<<","<<Item<<endl;

    }

    void SearchData()
    {
        system("cls");
        ShopName b;
        b.Dragors();
        coordinate c;
        c.gotoxy(28, 15);
        cout<<"Enter ID to search  :  ";
        string id;
        cin>>id;
        cout<<endl;
        ifstream fin("ProductList.txt");
        string line;
        int n = 0;
        float f;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string id_;
            string dummy;
            getline(sin, id_, ',');

            if(id_ == id)
            {
                c.gotoxy(28, 17);
                cout<<"ID Number       :  "<<id_<<endl;
                getline(sin, dummy, ',');
                c.gotoxy(28, 19);
                cout<<"Brand           :  "<<dummy<<endl;
                c.gotoxy(28, 21);
                getline(sin, dummy, ',');
                cout<<"Processor       :  "<<dummy<<endl;
                c.gotoxy(28, 23);
                getline(sin, dummy, ',');
                cout<<"Ram             :  "<<dummy<<endl;
                c.gotoxy(28, 25);
                getline(sin, dummy, ',');
                cout<<"Rom             :  "<<dummy<<endl;
                c.gotoxy(28, 27);
                getline(sin, dummy, ',');
                cout<<"Generation      :  "<<dummy<<endl;
                c.gotoxy(28, 29);
                getline(sin, dummy, ',');
                cout<<"Date of Store   :  "<<dummy<<endl;
                c.gotoxy(28, 31);
                getline(sin, dummy, ',');
                cout<<"Price           :  "<<dummy<<endl;
                c.gotoxy(28,33);
                getline(sin, dummy, ',');
                cout<<"Item            :  "<<dummy<<endl;



                c.gotoxy(28, 37);
                cout<<"PRESS ANY KEY TO CONTINUE...!!!!";
                n++;
                break;
            }

        }

        if(n == 0)
        {
            c.gotoxy(28, 17);
            cout<<"ACCOUNT NOT FOUND...!!!"<<endl;
            c.gotoxy(28, 19);
            cout<<"PRESS ANY KEY TO CONTINUE...!!!!";
        }

        getchar();
        getchar();
    }

    void UpdateData()
    {
        system("cls");
        ShopName b;
        b.Dragors();
        coordinate c;
        c.gotoxy(25, 15);
        cout<<"Enter ID to update data : ";
        string id;
        cin>>id;
        cin.ignore();
        int choice;
        ifstream fin("ProductList.txt");
        ofstream fout("temp.txt", fstream :: app);
        string line, dummy;
        string new_Brand, new_Processor, new_Ram, new_Rom, new_Generation, new_Date_of_store;
        int new_Price, new_Item;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string id_;
            getline(sin, id_,',');

            if(id == id_)
            {
                Modify_Menu();

                //char choice;
                scanf("%d",&choice);
                //c.gotoxy(28, )
                if(choice == 1)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter Updated name  : ";
                    cin.ignore();
                    getline(cin,new_Brand);
                    fout<<new_Brand<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                    // break;
                }
                else if(choice == 2)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter updated processor : ";
                    cin.ignore();
                    getline(cin,new_Processor);
                    fout<<new_Processor<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }
                else if(choice == 3)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter updated Ram : ";
                    cin.ignore();
                    getline(cin,new_Ram);
                    fout<<new_Ram<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }
                else if(choice == 4)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter updated Rom : ";
                    cin>>new_Rom;
                    fout<<new_Rom<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }
                else if(choice == 5)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter Generation : ";
                    cin>>new_Generation;
                    fout<<new_Generation<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }
                else if(choice == 6)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter Date of store : ";
                    cin>>new_Date_of_store;
                    fout<<new_Date_of_store<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }
                else if(choice == 7)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"\t\t\tEnter Price : ";
                    cin>>new_Price;
                    fout<<new_Price<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }
                else if(choice == 8)
                {
                    fout<<id_<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    fout<<dummy<<",";
                    getline(sin, dummy, ',');
                    cout<<"Enter Updated item : ";
                    cin>>new_Item;
                    fout<<new_Item<<",";
                    sin>>dummy;
                    fout<<dummy<<endl;
                }



            }
            else
            {
                fout<<id_<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                sin>>dummy;
                fout<<dummy<<endl;
            }
        }

        fin.close();
        fout.close();

        remove("ProductList.txt");
        rename("temp.txt","ProductList.txt");
    }

    void DeleteProduct()
    {
        system("cls");
        ShopName b;
        b.Dragors();
        coordinate c;
        c.gotoxy(26, 15);
        cout<<"Enter ID you want to delete : ";
        string id;
        cin>>id;
        cin.ignore();
        int n = 0;
        ifstream fin("ProductList.txt");
        ofstream fout("temp.txt", fstream :: app);
        ofstream fpush("history.txt", fstream :: app);
        string line, dummy;

        while(getline(fin,line))
        {
            stringstream sin(line);
            string id_;
            getline(sin, id_,',');

            if(id == id_)
            {
                fpush<<id_<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                getline(sin, dummy, ',');
                fpush<<dummy<<",";
                sin>>dummy;
                fpush<<dummy<<endl;
                n++;
            }
            else
            {
                fout<<id_<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                getline(sin, dummy, ',');
                fout<<dummy<<",";
                sin>>dummy;
                fout<<dummy<<endl;
            }
        }

        fin.close();
        fout.close();
        fpush.close();

        remove("ProductList.txt");
        rename("temp.txt","ProductList.txt");

        if(n == 0)
        {
            c.gotoxy(26, 20);
            cout<<"PRODUCT NOT FOUND.....!!!!"<<endl;
            c.gotoxy(26, 23);
            cout<<"PRESSS ANY KEY TO CONTINUE...!!!"<<endl;
        }
        else
        {
            c.gotoxy(26, 20);
            cout<<"PRODUCT  DELETED SUCCESSFULLY....!!!!"<<endl;
            c.gotoxy(26, 23);
            cout<<"PRESS ANY KEY TO CONTINUE...!!!!"<<endl;
        }
        getchar();
    }

    //ei obdi
    void ShowList()
    {
        // system("cls");
        ShopName b;
        b.Dragors();
        cout<<endl<<endl<<endl<<endl;
        cout<<"  ID  |       Brand        |       Date of store     |      Price     |   Current Item  "<<endl;
        ifstream fin("ProductList.txt");
        string line;
        int n,i;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string dummy;
            getline(sin, dummy, ',');
            cout<<setw(2)<<" "<<dummy<<" | ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(17)<<left<<dummy<<" |  ";
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            getline(sin, dummy, ',');
            cout<<" "<<setw(21)<<left<<dummy<<" | ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(13)<<left<<dummy<<" | ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(9)<<left<<dummy<<endl;


        }

        getchar();
        getchar();
    }
    void ShowCustomer()
    {
        // system("cls");
        ShopName b;
        b.Dragors();
        cout<<endl<<endl<<endl<<endl;
        cout<<"  ID  |       Name         |       Phone Number     "<<endl;
        cout<<"------|--------------------|------------------------"<<endl;
        ifstream fin("CustomerList.txt");
        string line;
        int n,i;
        while(getline(fin,line))
        {
            stringstream sin(line);
            string dummy;
            getline(sin, dummy, ',');
            cout<<setw(2)<<" "<<dummy<<" | ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(17)<<left<<dummy<<" |  ";
            getline(sin, dummy, ',');
            cout<<" "<<setw(9)<<left<<dummy<<endl;


        }

        getchar();
        getchar();
    }

    friend ostream& operator<<(ostream &out, Admin c)
    {
        out<<setw(2)<<c.ID<<" | "<<setw(17)<<left<<c.Ram<<" | "<<" "<<c.price<<"$";
    }

    friend void SortedData();

};



void SortedData()
{
    ShopName b;
    b.Dragors();
    coordinate cc;
    ifstream fin("ProductList.txt");
    Admin c;
    string line;
    int n,i;
    while(getline(fin,line))
    {
        stringstream sin(line);
        string dummy;
        getline(sin, dummy, ',');
        char a = dummy[0] - '0';
        char b = dummy[1] - '0';
        char d = dummy[2] - '0';
        c.setID((int)((int)a) * 100 + ((int)b) * 10 + ((int)d));
        getline(sin, dummy, ',');
        c.setBrand(dummy);
        getline(sin, dummy, ',');
        c.setProcessor(dummy);
        getline(sin, dummy, ',');
        c.setRam(dummy);
        getline(sin, dummy, ',');
        c.setRom(dummy);
        getline(sin, dummy, ',');
        c.setGeneration(dummy);
        getline(sin, dummy, ',');
        c.setDate_of_store(dummy);
        getline(sin,dummy,',');
        //sin>>n;
        c.setPrice(dummy);
        getline(sin, dummy, ',');
        //sin>>i;
        //cout<<"I"<<i<<endl;
        c.setItem(stoi(dummy));
        v.push_back(c);
    }

    auto f = [](Admin &c1, Admin &c2)
    {
        return c1.ID < c2.ID;
    };
    auto g = [](Admin &c1, Admin &c2)
    {
        return c1.Ram < c2.Ram;
    };
    auto h = [](Admin &c1, Admin &c2)
    {
        return c1.price < c2.price;
    };

    cc.gotoxy(29, 15);
    cout<<"How would you like to sort the records? == ";
    int nnn;

    cc.gotoxy(29, 18);
    cout<<"1. ID"<<endl;
    cc.gotoxy(29,19);
    cout<<"2. Ram"<<endl;
    cc.gotoxy(29, 20);
    cout<<"3. Price"<<endl;
    cin>>nnn;

    if(nnn == 1)
    {
        sort(v.begin(), v.end(), f);

    }
    else if(nnn == 2)
    {
        sort(v.begin(), v.end(), g);

    }
    else if(nnn == 3)
    {
        sort(v.begin(), v.end(), h);

    }


    cc.gotoxy(0, 23);
    cout<<" ID |       Ram         |  Current Price "<<endl;

    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }

    cout<<"\n\n\t\t\tPRESS ANY KEY TO CONTINUE....!!!!"<<endl;
    v.clear();
    getchar();
    getchar();


}

void Process()
{
    char mainchoice;
    Menu m;
    Admin c;

    while(1)
    {

        mainchoice  = getchar();
        switch(mainchoice)
        {
        case '1':
            system("cls");
            c.InputInformation();
            m.ShowMenu();
            break;
        case '2':
            system("cls");
            c.ShowList();
            m.ShowMenu();
            break;
        case '3':
            system("cls");
            c.UpdateData();
            m.ShowMenu();
            break;

        case '4':
            system("cls");
            c.DeleteProduct();
            m.ShowMenu();
            break;
        case '5':
            system("cls");
            c.SearchData();
            m.ShowMenu();
            break;
        case '6':
            system("cls");
            SortedData();
            m.ShowMenu();
            break;
        case '7':
            system("cls");
            c.ShowCustomer();
            m.ShowMenu();
            break;
        case '8':
            exit(0);
        }
    }
}


int main()
{
y:
    ShopName b;
    b.Dragors();
    coordinate c;
    c.gotoxy(28,15);
    printf("\n                         1.Admin\n");
    printf("                         2.Customer\n");
    printf("\t\t  Enter Your choice.... ");
    int n;
    scanf("%d",&n);
    if(n==1)
    {

        system("cls");
x:
        b.Dragors();
        c.gotoxy(28,15);
        printf("Enter Correct Password :");
        string s;
        cin>>s;
        if(s=="Dragors")
        {
            Menu m;
            m.ShowMenu();
            Process();
        }
        else
        {
            system("cls");
            c.gotoxy(28,12);
            printf("Wrong Password!!");
            goto x;
        }
    }
    else if(n==2)
    {
z:
        system("cls");
        b.Dragors();
        Product *bptr;
        Customer c;
        bptr= &c;
        c.gotoxy(28,15);
        printf("\n                         1.show Product Item\n");
        printf("                         2.exit\n");
        printf("\t\t  Enter Your choice.... ");
        int nn;
        scanf("%d",&nn);
        if(nn==1)
        {
            system("cls");
            b.Dragors();
            bptr->ShowList();     //polymorphism


            printf("\n                         1.Buy Item\n");
            printf("                         2.exit\n");
            printf("\t\t  Enter Your choice.... \n\n");
            int nnn;
            cin>>nnn;
            if(nnn==1)
            {
                string P_id;
                //getchar();
                cout<<"\t\t Enter Product Serial Number you want to Buy : ";
                cin>>P_id;
                int x=c.Buy_product(P_id);
                if(x)
                c.Updateitem(P_id);
                goto z;
            }
        }
        else if(nn==2)
        {
            exit(0);
        }
    }
    else
    {
        system("cls");
        c.gotoxy(28,12);
        printf("Error code entered...please enter correct code..!!");

        goto y;
    }

}
