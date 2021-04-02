#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
    int n,m,start,len_stop;
    ifstream fin("input.in");
    fin>>n;
    fin>>m;
    int matrice_muchii[m][2];
    char sir_litere[m];
    for(int i=0;i<m;i++){
        fin>>matrice_muchii[i][0];
        fin>>matrice_muchii[i][1];
        fin>>sir_litere[i];
    }
    fin>>start;
    fin>>len_stop;
    int stop[len_stop];
    for(int i=0;i<len_stop;i++){
        fin>>stop[i];
    }
    char sir_cuvinte[255]="",s0[20],*cuvant_curent;
    int nr_cuv;
    fin>>nr_cuv;
    for(int i=0;i<nr_cuv;i++){
        fin>>s0;
        strcat(sir_cuvinte,s0);
        strcat(sir_cuvinte," ");
    }
    cuvant_curent=strtok(sir_cuvinte," ");
    int ok=1,ok1=0,i,ii,anterior,contor,traseu[1000];
    cout<<endl<<"Output:"<<endl;
    while(cuvant_curent){
        ok=1;
        ok1=0;
        i=0;
        while(i<m && ok1==0){
            if(sir_litere[i]==cuvant_curent[0] && matrice_muchii[i][0]==start) ok1=1;
            i++;
        }
        ok=ok1;
        ok1=0;
        i=0;
        while(i<m && ok1==0 && ok==1){
            for(int j=0;j<len_stop;j++){
                if(sir_litere[i]==cuvant_curent[strlen(cuvant_curent)-1] && matrice_muchii[i][1]==stop[j]) ok1=1;
            }
            i++;
        }
        ok=ok1;
        i=0;
        anterior=start;
        contor=0;
        traseu[contor]=anterior;
        while(i<strlen(cuvant_curent) && ok==1){
            ok1=0;
            for(int j=0;j<m;j++){
                if(anterior==matrice_muchii[j][0] and cuvant_curent[i]==sir_litere[j] and ok1==0){
                    ok1=1;
                    anterior=matrice_muchii[j][1];
                    contor++;
                    traseu[contor]=anterior;
                }
            }
            ok=ok1;
            i++;
        }
        if(ok==1){
            cout<<"DA"<<endl<<"Traseu: ";
            for(i=0;i<=contor;i++){
                cout<<traseu[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<"NU"<<endl;
        cuvant_curent=strtok(NULL," ");
    }

}
