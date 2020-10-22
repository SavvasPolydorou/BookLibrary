#include <iostream>
using namespace std;

struct book_t
{
    string ISBN,title, category;
    bool available;
};

void bubblesort(book_t A[], int N){
    bool sorted;
    book_t temp;
    do{
        sorted = true;
        for(int i=0;i<N-1;i++)
            if (A[i].ISBN>A[i+1].ISBN){
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                sorted = false;
            }

    } while (sorted==false);
}

int main()
{
    int B,i;

    cout<<"Number of books:";
    cin>>B;
    book_t books[B];

    for(i=0;i<B;i++)
    {
        cout<<"Please give the ISBN, Title and Category for the "<<i+1<<" book:";
        cin>>books[i].ISBN>>books[i].title>>books[i].category;
        books[i].available=true;
    }

    bubblesort(books, B);
    string user_ISBN;
    bool found;
    int choice;
    do{
        cout<<"1. Book rent"<<endl;
        cout<<"2. Book return"<<endl;
        cout<<"3. All the available books"<<endl;
        cout<<"4. All rented books"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choose between 1-5:";
        cin>>choice;

        switch(choice)
        {
        case 1: //Book rent
            cout<<"ISBN:";
            cin>>user_ISBN;
            found=false;
            i=0;
            while((found!=true)&&(i<B))
            {
                if(user_ISBN==books[i].ISBN)
                {
                    found=true;
                    if(books[i].available==true)
                    {
                        cout<<"The book can be rented!"<<endl;
                        books[i].available=false;
                    }
                    else
                        cout<<"The book is NOT available!"<<endl;
                }
                i++;
            }
            if(found==false)
                cout<<"There is no such book!"<<endl;
            break;

        case 2: //Book return
            cout<<"ISBN:";
            cin>>user_ISBN;
            found=false;
            i=0;
            while((found!=true)&&(i<B))
            {
                if(user_ISBN==books[i].ISBN)
                {
                    found=true;
                    if(books[i].available==false)
                    {
                        cout<<"The book is now available!"<<endl;
                        books[i].available=true;
                    }
                    else
                        cout<<"The book was not rented!"<<endl;
                }
                i++;
            }
            if(found==false)
                cout<<"There is no such book!"<<endl;
            break;

        case 3:
            cout<<"Available books:"<<endl;
            for(i=0;i<B;i++)
                if(books[i].available==true)
                    cout<<books[i].title<<" "<<books[i].ISBN<<" "<<books[i].category<<endl;
            break;

        case 4:
            cout<<"Rented books:"<<endl;
            for(i=0;i<B;i++)
                if(books[i].available==false)
                    cout<<books[i].title<<" "<<books[i].ISBN<<" "<<books[i].category<<endl;
            break;

        case 5:
            cout<<"Bye!";
            break;

        default:
            cout<<"Wrong choice input!"<<endl;
        }

    }while(choice!=5);

}
