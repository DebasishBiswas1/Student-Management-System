#include<bits/stdc++.h>
using namespace std;
int main(){

    char data[20]; //max length of the name of the students to be 20
    int n=0,option=0,count_n=0;

    string empty = "00";//initial marks of the subjects
    string proctor = "";

    ifstream f("Example.txt");//Name of the file stored as "Example.txt"
    string line;

    for(int i=0; getline(f,line); ++i){
        count_n++;
    }//counting total number of lines in the file

    while(option!=6){//total no of options
        cout<<"\nAvailable Options: \n1. Add new students\n2. Students Login\n3. Faculty Login\n4. Proctor login\n5. Admin View\n6. Exit\nEnter option: ";
        cin>>option;

        if(option ==1 ){
            cout<<"Enter the number of students: ";
            cin>>n;

            count_n + count_n +n;

            for(int i=0;i<n;i++){
                ofstream outfile;
                outfile.open("Example.txt",ios::app);

                //entire data of student is stored line-by-line
                cout<<"Enter the registration number: ";
                cin>>data;
                outfile<<data<<"\t";

                cout<<"Enter your name: ";
                cin >> data;
                int len = strlen(data);

                while(len<20){
                    data[len]=' ';
                    len =len+1;
                }
                outfile << data <<"\t";

                //Inserting empty data into the file initially
                outfile << empty <<"\t";
                outfile << empty <<"\t";

                cout<<"Enter your proctor ID: ";
                cin >> proctor;

                outfile <<proctor <<endl;

            }
        }

        else if (option == 2){
            char reg_no[11];
            cout<<"Enter your registration number: ";
            cin >> reg_no;
            ifstream infile;
            int check = 0;
            infile.open("Example.txt",ios::in);

            while(infile >> data){ //prints out the data according to the registration number specified
                if(strcmp(data,reg_no) == 0){
                    cout<<"\nRegitration Number: "<<data<<endl;
                    infile >> data;
                    cout << "Name: "<<data<<endl;

                    infile>>data;
                    cout << "ECE-001A mark:" << data<<endl;

                    infile>>data;
                    cout<< "ECE-001B mark:" <<data<<endl;

                    infile>>data;
                    cout<<"Proctor ID: "<<data<<endl;

                    infile.close();
                    check = 1;
                }
            }

            if(check == 0){
                cout << "No such registration number found!"<<endl;
            }
        }

        else if( option == 3){ //to view and add marks to te database of a student
            char subcode[8];
            cout<<"Enter your sub code: ";
            cin>>subcode;

            string code1="ECE-001A",code2="ECE-001B",mark="";
            ifstream infile;
            int check=0;

            cout<<"\nAvailable options: \n1. Add Data about Marks\n2. View Data\nEnter Options: ";
            cin>>option;

            if( option ==1 ){
                cout << "Warning! You need to add marks deetails about all students."<<endl;
                
                for(int i=0;i<count_n;i++){
                    fstream file("Exampl.txt");

                    if(strcmp(subcode,code1.c_str())==0){
                        file.seekp(26 + 37*i,ios_base::beg);
                        cout<<"Enter mark of the student#"<<(i+1)<<" : ";
                        cin>>mark;
                        file.write(mark.c_str(),2);
                    }

                    if(strcmp(subcode,code2.c_str())==0){
                        file.seekp(29 + 37*i,  ios_base::beg);
                        cout<<"Enter mark of the student#"<<(i+1)<<" : ";
                        cin>>mark;
                        file.write(mark.c_str(),2);   
                    }

                }
            }
            else if(option == 2){
                infile.open("Example.txt",ios::in);
                if(strcmp(subcode,code1.c_str())==0){ 
                    cout<<"Registration number - Marks\n"<<endl;
                    while(infile >> data){
                        cout << data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        infile >>  data;
                        check =1;

                        infile.close();
                        infile.open("Exmple.txt",ios::in);
                        if(strcmp(subcode,code2.c_str())==0){
                            cout<<"Registration number - Marks\n"<<endl;
                            while(infile>>data){
                                cout<<data;
                                infile>>data;
                                infile>>data;
                                infile>>data;
                                cout<<" - "<<data<<endl;
                                infile >> data;
                                check =1;
                            }
                        }
                    }
                    infile.close();
                    if(check==0){
                        cout<<"No such subject code found!"<<endl;
                    }
                }
            }
        }

        else if(option == 4 ){ //Displays all details of students under the same proctor ID

            char procid[7];
            cout<<"Enter your Proctor ID: ";
            cin>> procid;
            int check=0;

            char temp1[100],temp2[100],temp3[100],temp4[100],id[100];
            ifstream infile;
            infile.open("Example.txt",ios::in);

            while(infile >> temp1){
                infile >> temp2;
                infile >> temp3;
                infile >> temp4;
                infile >> id;

                if (strcmp(id,procid)==0){
                    cout << "\nRegistration Number: "<<temp1<<endl;
                    cout<<"Name: "<<temp2<<endl;
                    cout<<"ECE-001A Mark: "<<temp3<<endl;
                    cout<<"ECE-001B Mark: "<<temp4<<endl;
                    check=1;

                }
            }
            
            if(check ==0){
            cout<<"No such Proctor ID found!"<<endl;
            }
        }

        else if(option==5){
            char password[25];
            cout<<"Enter the Password: ";
            cin>>password;

            string admin_pass="admin";

            if(strcmp(password,admin_pass.c_str())==0){
                cout << "Reg No.\tName\tECE-001A\tECE-001B\tProctor Id"<<endl;

                ifstream infile;
                infile.open("Example.txt",ios::in);
                char data[20];

                while(infile >> data){
                    cout<<data<<"\t";
                    infile>>data;
                    cout<<data<<"\t";
                    infile>>data;
                    cout<<data<<"\t";
                    infile>>data;
                    cout<<data<<"\t";
                    infile>>data;
                    cout<<data<<endl;
                }
            }
        }
        

    }


    return 0;
}