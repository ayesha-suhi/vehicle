#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

class vpp
{

private:

    int bike=0, car=0, micro=0;

    char li_no[30];
    char vechicle_name [30];
    char vechicle_owner [30];
    char parking_time [30];

public:

    void bike_i()
    {
        cout<<"\n.......Enter Bike Parking Information.......";

        ofstream fout("Record.txt",ios::app);

        int s, flag=0;
        cout<<"\n\n Serial/Token Number: ";
        cin>>s;

        flag=check(s);

        if(flag==1)
            cout<<"\n Sorry..!!!Parking is already full.";

        else
        {
            bike = s;
            cin.ignore();

            cout<<"\n License Number: ";
            gets(li_no);

            cout<<"\n Bike Brand: ";
            gets(vechicle_name);

            cout<<"\n Bike Owner Name: ";
            gets(vechicle_owner);

            cout<<"\n Parking Time: ";
            gets(parking_time);

            cout<<"\n\tBike Parked."<<endl;

            fout.write((char*)this, sizeof(*this));
            fout.close();
        }
    }


    int check(int s)
    {
        int flag=0;
        ifstream fin("Record.txt",ios::in);
        while(!fin.eof())
        {
            fin.read((char*)this,sizeof(*this));
            if( bike == s )
            {
                flag=1;
                break;
            }
        }

        fin.close();
        return(flag);
    }


    void car_i()
    {
        cout<<"\n.......Enter Car Parking Information.......";

        ofstream fout1("Record1.txt",ios::app);

        int t,flag=0;

        cout<<"\n\n Serial/Token Number: ";
        cin>>t;

        flag=check1(t);

        if(flag==1)
            cout<<"\n Sorry..!!!Parking is already full";

        else
        {
            car = t;
            cin.ignore();

            cout<<"\n License Number: ";
            gets(li_no);

            cout<<"\n Car Brand: ";
            gets(vechicle_name);

            cout<<"\n Car Owner Name: ";
            gets(vechicle_owner);

            cout<<"\n Parking Time: ";
            gets(parking_time);

            cout<<"\n\t Car Parked."<<endl;

            fout1.write((char*)this, sizeof(*this));
            fout1.close();
        }
    }

    int check1(int t)
    {
        int flag=0;
        ifstream fin1("Record1.txt",ios::in);
        while(!fin1.eof())
        {
            fin1.read((char*)this,sizeof(*this));
            if( car == t )
            {
                flag=1;
                break;
            }
        }
        fin1.close();
        return(flag);
    }


    void micro_i()
    {
        cout<<"\n.......Enter Micro Parking Information.......";

        ofstream fout2("Record2.txt",ios::app);

        int u,flag=0;

        cout<<"\n\n Serial/Token Number: ";
        cin>>u;
        flag=check2(u);

        if(flag==1)
            cout<<"\n Sorry..!!!Parking is already full";

        else
        {
            micro = u;
            cin.ignore();

            cout<<"\n License Number: ";
            gets(li_no);

            cout<<"\n Micro Brand: ";
            gets(vechicle_name);

            cout<<"\n Micro Owner Name: ";
            gets(vechicle_owner);

            cout<<"\n Parking Time: ";
            gets(parking_time);


            cout<<"\n\t Micro Parked."<<endl;

            fout2.write((char*)this, sizeof(*this));
            fout2.close();
        }
    }

    int check2(int u)
    {
        int flag=0;
        ifstream fin2("Record2.txt",ios::in);
        while(!fin2.eof())
        {
            fin2.read((char*)this,sizeof(*this));
            if( micro == u )
            {
                flag=1;
                break;
            }
        }
        fin2.close();
        return(flag);
    }



    void VPPDetailBikes()
    {
        ifstream fin("Record.txt",ios::in);
        fin.read((char*)this,sizeof(*this));
        cout<<"\n\n----------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                           Bike Parking Dashboard                                         "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;

        while(!fin.eof())
        {
            cout<<"\n  Parking No: "<< bike <<"  ||  License no: "<<li_no<<"  ||  Brand: "<<vechicle_name<<"  ||  Owner: "<<vechicle_owner<<"  ||  Parking Time: " << parking_time<<endl<<endl;
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }



    void VPPDetailCar()
    {
        ifstream fin1("Record1.txt",ios::in);
        fin1.read((char*)this,sizeof(*this));

        cout<<"\n\n----------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                           Car Parking Dashboard                                          "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;

        while(!fin1.eof())
        {
            cout<<"\n  Parking No: "<< car <<"  ||  License no: "<<li_no<<"  ||  Brand: "<<vechicle_name<<"  ||  Owner: "<<vechicle_owner<<"  ||  Parking Time: " << parking_time<<endl<<endl;

            fin1.read((char*)this,sizeof(*this));
        }
        fin1.close();
    }



    void VPPDetailMicro()
    {
        ifstream fin2("Record2.txt",ios::in);
        fin2.read((char*)this,sizeof(*this));
        cout<<"\n\n----------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                          Micro Parking Dashboard                                         "<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
        while(!fin2.eof())
        {
            cout<<"\n  Parking No: "<< micro <<"  ||  License no: "<<li_no<<"  ||  Brand: "<<vechicle_name<<"  ||  Owner: "<<vechicle_owner<<"  ||  Parking Time: " << parking_time<<endl<<endl;
            fin2.read((char*)this,sizeof(*this));
        }
        fin2.close();
    }



    int delete_bike (int t)
    {
        ifstream fin;
        ofstream fout;

        fin.open("Record.txt", ios::in| ios::binary);
        fout.open("temp.txt", ios::out| ios::binary);
        fin.read((char*)this, sizeof(*this));
        if (!fin)
            cout << "Not Found\n";
        else
        {
            while(!fin.eof())
            {
                if(bike != t)
                {
                    fout.write((char*)this, sizeof(*this));
                }

                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
            fout.close();
            remove("Record.txt");
            rename("temp.txt","Record.txt");

        }
    }



    int delete_car (int t)
    {

        ifstream fin1;
        ofstream fout1;

        fin1.open("Record1.txt", ios::in| ios::binary);

        if (!fin1)
            cout << " Not Found\n";

        else
        {
            fout1.open("temp1.txt", ios::out| ios::binary);
            fin1.read((char*)this, sizeof(*this));

            while(!fin1.eof())
            {
                if(car != t)
                    fout1.write((char*)this, sizeof(*this));

                fin1.read((char*)this, sizeof(*this));
            }
            fin1.close();
            fout1.close();
            remove("Record1.txt");
            rename("temp1.txt","Record1.txt");

        }
    }



    int delete_micro (int t)
    {

        ifstream fin2;
        ofstream fout2;

        fin2.open("Record2.txt", ios::in| ios::binary);

        if (!fin2)
            cout << " Not Found\n";

        else
        {

            fout2.open("temp2.txt", ios::out| ios::binary);
            fin2.read((char*)this, sizeof(*this));

            while(!fin2.eof())
            {

                if(micro != t)

                    fout2.write((char*)this, sizeof(*this));

                fin2.read((char*)this, sizeof(*this));
            }
            fin2.close();
            fout2.close();
            remove("Record2.txt");
            rename("temp2.txt","Record2.txt");

        }
    }


};

int header()
{

    system("cls");

    int u_input;

    cout<<"\n:----------------------------------------------------------------:"<<endl;
    cout<<":                                                                :"<<endl;
    cout<<":                         WELCOME                                :"<<endl;
    cout<<":                                                                :"<<endl;
    cout<<":----------------------------------------------------------------:"<<endl;
    cout<<":----------------------------------------------------------------:"<<endl;
    cout<<":               VEHICLE  PARKING  RECORD  SYSTEM                 :"<<endl;
    cout<<":----------------------------------------------------------------:"<<endl;
    //cout<<"\n****************";
    cout<<"\n\t 1. Parking"<<endl;
    cout<<"\n\t 2. Show The Record"<<endl;
    cout<<"\n\t 3. Delete The Record"<<endl;
    cout<<"\n\t 4. Exit From The System"<<endl;

    cout<<"\n\n\tEnter your choice: ";
    cin>>u_input;
    return u_input;

}



int main()
{
    vpp v;
    int x;
    int a;

    int title;

    while (1)
    {

        switch(header())
        {
        case 1:
            system("cls");

            cout<<":----------------------------------------------------------------:"<<endl;
            cout<<":                    PARKING A VEHICLE RECORD                    :"<<endl;
            cout<<":----------------------------------------------------------------:"<<endl;

            cout<<"\n\t 1. Bike"<<endl;
            cout<<"\n\t 2. Car"<<endl;
            cout<<"\n\t 3. Micro"<<endl;
            cout<<"\n\n\tEnter your choice: ";
            cin>>x;
            if(x==1){
                v.bike_i();
                getch();
                break;
            }

            else if(x==2){
                v.car_i();
                getch();
                break;
            }

            else if(x==3){
                v.micro_i();
                getch();
                break;
            }
            else{
                getch();
                break;
            }


        case 2:
            system("cls");

            cout<<":----------------------------------------------------------------:"<<endl;
            cout<<":               SHOWING VEHICLE  PARKING  RECORD                 :"<<endl;
            cout<<":----------------------------------------------------------------:"<<endl;

            cout<<"\n\t 1. Bike"<<endl;
            cout<<"\n\t 2. Car"<<endl;
            cout<<"\n\t 3. Micro"<<endl;

            cout<<"\n\n\tEnter your choice: ";
            cin>>x;

            if(x==1){
                v.VPPDetailBikes();
                getch();
                break;
            }

            else if(x==2){
                v.VPPDetailCar();
                getch();
                break;
            }

            else if(x==3){
                v.VPPDetailMicro();
                getch();
                break;
            }

            else{
                getch();
                break;
            }

        case 3:
        {
            system("cls");

            cout<<":----------------------------------------------------------------:"<<endl;
            cout<<":              DELETING VEHICLE  PARKING  RECORD                 :"<<endl;
            cout<<":----------------------------------------------------------------:"<<endl;

            cout<<"\n\t 1. Bike"<<endl;
            cout<<"\n\t 2. Car"<<endl;
            cout<<"\n\t 3. Micro"<<endl;

            cout<<"\n\n\tEnter your choice: ";
            cin>>x;

            if(x==1)
            {

                v.VPPDetailBikes();
                cout<<"\n Enter Parking Number To Delete: ";

                cin >> title;
                v.delete_bike(title);

                cout<<"\n\n\tInformation Deleted";
                getch();
                break;

            }
            else if(x==2)
            {
                v.VPPDetailCar();

                cout<<"\n Enter Parking Number To Delete: ";
                cin >> title;

                v.delete_car(title);

                cout<<"\n\n\tInformation Deleted";
                getch();
                break;
            }
            else if(x==3)
            {
                v.VPPDetailMicro();
                cout<<"\n Enter Parking Number To Delete: ";

                cin >> title;

                v.delete_micro(title);

                cout<<"\n\n\tInformation Deleted";
                getch();
                break;
            }
            else
            {
                getch();
                break;

            }

        }

        case 4:
            exit (0);

        default:
            cout<<"\n Invalid Choice.";
            getch();
        }
    }
    return 0;
}
