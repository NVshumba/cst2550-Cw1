
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int failure=0;
int success=0;
void Trans(int a)                                 //counts the total failed and successful transaction
{
    if(a==0)
        failure++;
    else
        success++;
}
class book
{
private:
    int bookcode;
    string author;
    string title;
    double price;
    string publisher;
    int stock;

    void priceUpdate()        //to update price
    {
        cout<<"\nEnter the new price: ";
        cin>>price;
        cout<<endl;
    }
    void stockUpdate()                                             //to update stock
    {
        cout<<"\nEnter the new stock: ";
        cin>>stock;
        cout<<endl;
    }
public:
    book(int u,string x,string y,string z, double w, int v)            //constructor
    {
        bookcode=u;
        title=x;
        author=y;
        publisher = z;
        price = w ;
        stock = v;
    }
    book(string x,string y)                                             //constructor
    {
        author=x;
        publisher=y;
    }
    int search(book x)                                                  //searching the book in the list
    {
        if(author==x.author&&publisher==x.publisher)
            return 1;
        else
            return 0;
    }};




void getItem()
{
    fstream file;
    int stock,price;
    string item,id,name;
    cout<<"Display Items";
    file.open("items.txt",ios::in);
    if(!file)
    cout<<"Error Opening File";
    else
    {
        cout<<"\n\n Item_Type    Item_ID     Item_Name   Stock   Price\n\n";
        file>>item>>id>>name>>stock>>price;
        while(!file.eof())
        {
            cout<<"     "<<item<<"      "<<id<<"        "<<name<<"      "<<stock<<"     "<<price<<"\n\n";
            file>>item>>id>>name>>stock>>price;
        }
        file.close();
    }
    
}

void addItem()
{
    
    fstream txt;
    int copies,price;
    string item,id,name;
     cout<<" Add New Item";
     cout<<" Item Type: ";
     cin>>item;
     cout<<" Item ID: ";
     cin>>id;
     cout<<" Item Name: ";
     cin>>name;
     cout<<" Number Of Item: ";
     cin>>copies;
     cout<<" Price Of Item: ";
     cin>>price;
     txt.open("items.txt",ios::out|ios::app);
     txt<<"    "<<item<<"   "<<id<<"   "<<name<<"  "<<copies<<" "<<price<<"\n";
}

void deleteItem()
{
    fstream file,file2;
    int copies,price,error=0;
    string item,id2,id,name;
    file.open("items.txt",ios::in);
    file2.open("items1.txt",ios::app|ios::out);
    if(!file)
    cout<<"\n\n Error Opening File...";
    else
    {
        cout<<"Item ID: ";
        cin>>id;
        file>>item>>id2>>name>>copies>>price;
        while(!file.eof())
        {
            if(id == id2)
            {
                system("cls");
                cout<<"\n\n Item Removed Successfully.. ";
                error++;
            }
            else
            file2<<"   "<<item<<"  "<<id2<<"   "<<name<<"    "<<copies<<"     "<<price<<"\n";
            file>>item>>id2>>name>>copies>>price;
            
        }
        if(error == 0)
        cout<<"\n\n Item ID not found";
}
file.close();
file2.close();
remove("items.txt");
rename("items1.txt","items.txt");
}

void sellItem()
{
    fstream file,file2;
    int copies,copies2,price,error=0,copies3;
    string item,id2,id,name;
    file.open("items.txt",ios::in);
    file2.open("items1.txt",ios::app|ios::out);
    if(!file)
    cout<<"Error";
    else
    {
        cout<<"\n\nItem ID: ";
        cin>>id2;
        file>>item>>id>>name>>copies>>price;
        while(!file.eof())
        {
            if(id2 == id)
            {
                cout<<" Sell Item\n\n";

                cout<<"\n\nEnter Quantity: ";
                cin>>copies2;
                copies3=copies-copies2;

                
                file2<<"    "<<item<<"   "<<id<<"   "<<name<<"  "<<copies3<<" "<<price<<"\n";
                error++;
            }
            else
            file2<<"   "<<item<<"  "<<id2<<"   "<<name<<"    "<<copies<<"     "<<price<<"\n";
            file>>item>>id2>>name>>copies>>price;
            
        }
        if(error == 0)
        cout<<"\n\n Item ID not found";
}
file.close();
file2.close();
remove("items.txt");
rename("items1.txt","items.txt");
}


void updateItem()
{
    fstream file,file2;
    int copies,copies2,price,price2,error=0;
    string item,item2,id2,name2,id,name;
    file.open("items.txt",ios::in);
    file2.open("items1.txt",ios::app|ios::out);
    if(!file)
    cout<<"Error";
    else
    {
        cout<<"Item ID: ";
        cin>>id2;
        file>>item>>id>>name>>copies>>price;
        while(!file.eof())
        {
            if(id2 == id)
            {
                cout<<" Update Item\n\n";

                cout<<" \n\n New Item Type: ";
                cin>>item2;
                cout<<" \n\n New Item Name: ";
                cin>>name2;
                cout<<" \n\n New Number Of Item: ";
                cin>>copies2;
                cout<<" \n\n New Price Of Item: ";
                cin>>price2;
                file2<<"    "<<item2<<"   "<<id<<"   "<<name2<<"  "<<copies2<<" "<<price2<<"\n";
                error++;
            }
            else
            file2<<"   "<<item<<"  "<<id2<<"   "<<name<<"    "<<copies<<"     "<<price<<"\n";
            file>>item>>id2>>name>>copies>>price;
            
        }
        if(error == 0)
        cout<<"\n\n Item ID not found";
}
file.close();
file2.close();
remove("items.txt");
rename("items1.txt","items.txt");
}


void seller()                                                    // seller options
{
    int a,n;
    while(1){
    cout<<"\nEnter ur choice: \n1.Show Items\n2.Update An Item\n3.Transactions\n4.Add An Item\n5. Delete An Item\n6.Exit"<<endl;
    cin>>a;
    cout<<endl;
    switch(a)
    {
        case 1: cout<<"\nItem Details: "<<endl;
                getItem();
                break;

        case 2: cout<<"Update an Item Update"<<endl;
                updateItem();
                    break;

        case 3: cout<<"Total failed transaction: "<<failure<<endl;
                cout<<"Total successful transaction: "<<success<<endl;
                cout<<endl;
                break;
        case 4:
                cout<<"Add An Item"<<endl;
                addItem();
                break;
        case 5:
                cout<<"Delete an Item"<<endl;
                deleteItem();
                break;
        case 6:
                return;
        default:
                cout<<"Error Input";
                break;
    }
   }
}
void customer()                                             //customer options
{
    int x;
    while(1)
    {
        cout<<"\nEnter a option \n1.Show Books\n2.Purchase a book\n3.Exit"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"\nItem Details: "<<endl;
            getItem();
            break;
        }

        else if(x==2)
        {
            cout<<"Buy An Item";
            sellItem();
            break;

        
        }
        else
            return;
    }
}

int main()
{
    int a;
    while(1)
    {
        cout<<"\nSelect any one\n1.Seller\n2.Customer\n3.Exit"<<endl;
        cin>>a;
        cout<<endl;
        if(a==1)
            seller();
        else if(a==2)
                customer();
        else
            return 0;
    }
}
