#include <iostream>
using namespace std;
int sw=0;
string game(int size,char sym,string input,string &server){
    string packet;
    int pos=0;
    int disp_row=0;
    for(int j=0;j<=size*2;j++){
        if(j%2==0||j==size*2){
            packet+="+";
          //  cout<<"+";
        }
        else{
            packet+="-"+to_string(j/2)+"-";
            //cout<<"-"<<j/2<<"-";
        }
    }
   // cout<<endl;
    packet+="\n";
    for(int i=0;i<=size*2;i++){
        if(i%2==0||i==size*2){
            for(int j=0;j<=size*2;j++){
                if(j%2==0||j==size*2){
                    //cout<<"+";
                    packet+="+";
                }
                else{
                    packet+="---";
                   // cout<<"---";
                }
            }
            packet+="\n";
            //cout<<endl;
        }
        else{
            for(int j=0;j<=size*2;j++){
                if(j%2==0||j==size*2){
                   // cout<<"+";
                    packet+="+";
                }
                else{

                    if(server[pos]-48==0&&input[pos]=='1'){
              //      packet+=" "+to_string(input[pos]-48)+" ";
                        //packet+=" "+to_string(sym)+" ";
                        packet+=" ";
                        packet+=sym;
                        packet+=" ";
                    server[pos]=sym;
                   // cout<<" "<<pos<<" ";
                    }
                    else{
                      //  packet+=" "+to_string(server[pos])+" ";
                        packet+=" ";
                        packet+=server[pos];
                        packet+=" ";
                    }
                    pos++;
                }
            }
            packet+="<----"+to_string(disp_row)+"\n";
            //cout<<"<----"<<disp_row<<endl;
            disp_row++;
        }
    }
    return packet;
}
string target(int size,int col,int row){
    string temp;
//    cout<<col<<" "<<row;
//    cout<<endl;
//    cout<<col+row*size;
    temp+="0";
    for(int i=0;i<size*size;i++){
        if(i==col+row*size)
            temp+="1";
        else{
            temp+="0";
        }
    }
  //  cout<<temp;
    return temp;
}
void Inter(int size,const char* in,string &server){
    string mes=in;

  if(in[0]=='1'){
      string chat;
      chat+="Chat: ";
      chat+=mes[1];
      chat+=" -  ";
      chat+=mes.substr(2,mes.size());

      cout<<chat;
      return ;
  }
  else{

      string client=in;
client=client.substr(1,client.size());
      cout<<endl;
      if(sw==0){
      cout << game(size,'O' ,client, server);
      sw=1;
      }
      else if(sw==1){
          cout << game(size,'X' ,client, server);
      sw=0;
      }
  }


}
string serverInit(int size,string &server){
    for(int i=0;i<size*size;i++){
        server[i]='0';
    }

}
void entry(int size,string & server){
    int choice;
    int i,j;
    string in;
    cout<<"0 -chat , 1- move";
    cin>>choice;
    cout<<endl;
    if(choice==0){
        cout<<"Message: ";
        cin>>in;
        in="1"+in;

    }
    else if(choice==1){
        cout<<"ROW|COL\n";
        cin>>i>>j;
        in=target(size,j,i);
    }
    Inter(size,in.c_str(),server);

}
int main() {
    string server="0001";
    string client="0101";
    int size=3;
    cout<<endl;
    cout<<endl;    cout<<endl;
    serverInit(size,server);
    cout << game(size, 'x',"0000", server);
    while(1) {
        entry(size,server);
        cout<<endl;
    }
    return 0;
}
