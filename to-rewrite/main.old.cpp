#include <iostream>
#include <fstream>
#include <map>
#include <time.h>
//#include "./namespace/all-commands.h"

#define RATTISH_PAYLOAD_PATH "payload.rat"
/*
struct

class ratScriptFile{
    ifstream MyReadFile;
    ratScriptInclusions* scriptIncluded=NULL;
    char** rawLines;
    int linesCount=0;

};

int readRatScript(char* )
*/

using namespace std;

map<char,char*> variableStore;

char currentContext='\0';

map<char,char*>::iterator contextVariable;

char beforeContext(char checkContext=currentContext){
    if(
        (checkContext<'a'||checkContext>'z')
        &&
        (checkContext<'A'||checkContext>'Z')
    )checkContext='a';
    contextVariable=variableStore.find(checkContext);
    if(contextVariable==variableStore.end()){
        variableStore.insert(pair<char,char*>(checkContext,new char[64]));
        contextVariable=variableStore.find(checkContext);
    }
    return checkContext;
}
map<char,char*>::iterator getVar(char keyname){
    if(
        (keyname<'a'||keyname>'z')
        &&
        (keyname<'A'||keyname>'Z')
    )keyname='a';
    map<char,char*>::iterator tmpVar=variableStore.find(keyname);
    if(tmpVar==variableStore.end()){
        variableStore.insert(pair<char,char*>(keyname,new char[64]));
        tmpVar=variableStore.find(keyname);
    }
    return tmpVar;
}
int intToCharArray(int num, char *numstr){
    char tmp[11];
    int i=0, j=0;
    bool minusSign=false;
    if(num<0){
        ++j;
        //tmp[i++]='-';
        minusSign=true;
        num=-num;
    }
    while(num>0){
        tmp[i++]='0'+(num%10);
        num/=10;
    }
    j+=i;
    if(minusSign)*(numstr++)='-';
    while(i)*(numstr++)=tmp[--i];
    return j;
}
bool shiftDecimalChar(char cipher, int &num){
    if(cipher>='0'&&cipher<='9'){
        num*=10;
        num+=cipher-'0';
        return true;
    }else return false;
}
int charArrayToInt(char *in){
    int out=0, sign=1;
    if(*in=='-'){
        in++;
        sign=-1;
    }
    char *argHook=in;
    while(shiftDecimalChar(*(argHook++), out));
    return out*sign;
}

typedef void (*ratCommand) ();//COMMAND CONTAINER STRUCTURE

ratCommand rattishDictionary[256];//ALL COMMAND CONTAINER,

char arguments[1000]="\0";
//string arguments="";
int argsCount=0;
char tmpCommand=0;

void commentaryBlank(){cout<<"commentary skipping";}

void pointContextToVariable(){
    currentContext=arguments[0];
}

void setContextValue(){
    currentContext=beforeContext();
    for(int i=0;i<64;i++){
        contextVariable->second[i]=arguments[i];
        if(arguments[i]=='\0')break;
    }
}
void addOrAppend(){
    currentContext=beforeContext();
    bool appendFlag=false;
    for(int i=0, j=0;i<64;i++){
        if(arguments[j]=='\0'){
            if(appendFlag)contextVariable->second[i]='\0';
            break;
        }
        if(contextVariable->second[i]=='\0'||appendFlag){
            appendFlag=true;
            contextVariable->second[i]=arguments[j++];
        }
    }
}
void substractOrSlice(){
    currentContext=beforeContext();
    int i=0;
    for(;i<64;i++)if(contextVariable->second[i]=='\0')break;
    int sliceLen=charArrayToInt(arguments);
    if(i>sliceLen)contextVariable->second[i-sliceLen]='\0';
    else contextVariable->second[0]='\0';
}
void multiplyOrGetCharAtIndex(){
    currentContext=beforeContext();
    int charindex=charArrayToInt(arguments);
    contextVariable->second[0]=contextVariable->second[charindex];
    contextVariable->second[1]='\0';
}
void divideOrGetLength(){
    currentContext=beforeContext();
    int i=0;
    for(;i<64;i++)if(contextVariable->second[i]=='\0')break;
    int j=intToCharArray(i, contextVariable->second);
    contextVariable->second[j]='\0';
}
void moduloOrReverse(){
    currentContext=beforeContext();
    int i=0, j=0;
    for(;i<64;i++)if(contextVariable->second[i]=='\0')break;
    j=i;
    char tmp='\0';
    for(i=0;i<j/2;i++){
        tmp=contextVariable->second[i];
        contextVariable->second[i]=contextVariable->second[j-i-1];
        contextVariable->second[j-i-1]=tmp;
    }
}
void copyFromContext(){
    currentContext=beforeContext();
    char *contextHook=contextVariable->second;
    char *varHook=getVar(arguments[0])->second;
    for(int i=0;i<64;i++){
        varHook[i]=contextHook[i];
        if(contextHook[i]=='\0')break;
    }
}
void copyToContext(){
    currentContext=beforeContext();
    char *contextHook=contextVariable->second;
    char *varHook=getVar(arguments[0])->second;
    for(int i=0;i<64;i++){
        contextHook[i]=varHook[i];
        if(varHook[i]=='\0')break;
    }
}
void press(){

}
void release(){

}
void print(){
    cout<<arguments;
    return;
}
void read(){
    currentContext=beforeContext();
    cout<<arguments;
    cin>>contextVariable->second;
    return;
}
void wait(){
    time_t waitStart=time(NULL);
    int tDelay=0, tPassed=0;
    char *argHook=arguments;
    while(shiftDecimalChar(*(argHook++), tDelay));
    do{
        tPassed=1000*(int)difftime(time(NULL),waitStart);
    }while(tDelay>tPassed);
}

void resetCommandList(){//SET AS DEFAULT ALL POSSIBLE COMMANDS TO COMMENT, to avoid unwanted errors
    for(short int i=0;i<256;i++){
        rattishDictionary[i]=commentaryBlank;
    }
}


void setRattishNamespaces(){
    //using rattishCore::rattishDictionary;
    //using namespace rattishCommands;

  rattishDictionary['<']=print;
  rattishDictionary['>']=read;
  rattishDictionary['.']=wait;
  rattishDictionary['_']=press;
  rattishDictionary['^']=release;

  rattishDictionary['$']=pointContextToVariable;
  rattishDictionary['=']=setContextValue;
  rattishDictionary['+']=addOrAppend;
  rattishDictionary['-']=substractOrSlice;
  rattishDictionary['*']=multiplyOrGetCharAtIndex;
  rattishDictionary[':']=divideOrGetLength;

  rattishDictionary['}']=copyFromContext;
  rattishDictionary['{']=copyToContext;

  rattishDictionary['%']=moduloOrReverse;

  //rattishDictionary['\\']=ifContextLesserThenVar;
  //rattishDictionary['/']=ifContextGreaterThenVar;
  //rattishDictionary['|']=ifContextEqualsVar;
  //rattishDictionary[';']=ifContextOrVar;
  //rattishDictionary['&']=ifContextAndVar;
  //rattishDictionary['~']=notContext;

  /* temporary deprecated
  rattishDictionary['[']=beginProcedure;
  rattishDictionary[']']=endProcedure;
  rattishDictionary['"']=globalEnviromentSwitcher;

  */

  //rattishDictionary['?']=ifOrder;

  //rattishDictionary['!']=labelOrder;

    rattishDictionary['#']=envSwitch;
    //rattishDictionary['\'']=debugEcho;
    rattishDictionary['@']=importScript;

}



void commandUseDebug(char coma){
    cout<<"COMMAND: "<<coma<<" ASCII:"<<(int)coma<<" ARGS: ";
}

bool waitForCommand=true;
bool argumentsInput=false;

int main()
{
    resetCommandList();
    setRattishNamespaces();
    ifstream ratFile;
    ratFile.open (RATTISH_PAYLOAD_PATH, ifstream::in);
    if(ratFile.is_open()){
        char c=0;
        while (ratFile.get(c)) {
            //cout<<c<<" "<<argumentsInput<<waitForCommand<<endl;
            if(c=='\n'||c=='\r'){
                if(argumentsInput){
                    arguments[argsCount]='\0';
                    rattishDictionary[tmpCommand]();
                    cout<<endl;
                }
                tmpCommand=0;
                //arguments="";
                arguments[0]='\0';
                argsCount=0;
                waitForCommand=true;
                argumentsInput=false;
            }
            else if(waitForCommand){
                tmpCommand=c;
                waitForCommand=false;
                argumentsInput=true;
            //}else arguments+=c;
            }else arguments[argsCount++]=c;
        }
        if(ratFile.eof()){
            cout<<"READED";
        }else{
            cout<<"ERROR_EOF NOT FOUND";
        }
        ratFile.close();
    }else{
        cout<<"CANT OPEN";
    }
    for (map<char,char*>::iterator it=variableStore.begin(); it!=variableStore.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    return 0;
}
