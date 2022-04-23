#include <iostream>
#include <fstream>
#include <map>
#include <time.h>
#include <queue>
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

using namespace std;

map<char,char*> variableStore;
map<char,char*>::iterator contextVariable;
int MAXVARLEN=64;
char *contextValue=NULL;
char context='\0';
char varnameValidator(char checkMe){
        if(
            (checkMe<'a'||checkMe>'z')
            &&
            (checkMe<'A'||checkMe>'Z')
        )checkMe='a';
        return checkMe;
    }
void safeContextProcedure(){
  context=varnameValidator(context);
  contextVariable=variableStore.find(context);
        if(contextVariable==variableStore.end()){
            variableStore.insert(pair<char,char*>(context,new char[MAXVARLEN]));
            contextVariable=variableStore.find(context);
        }
        contextValue=contextVariable->second;
    }
    char *getVariable(char keyname){
        keyname=varnameValidator(keyname);
        map<char,char*>::iterator tmpVar=variableStore.find(keyname);
        if(tmpVar==variableStore.end()){
            variableStore.insert(pair<char,char*>(keyname,new char[MAXVARLEN]));
            tmpVar=variableStore.find(keyname);
        }
        return tmpVar->second;
    }
    int varLimit(){return MAXVARLEN;}

char arguments[1000]="\0";
//string arguments="";
int argsCount=0;
char currentCommand=0;

void appendArg(char data){
    arguments[argsCount++]=data;
}
void lineReset(){
    currentCommand=0;
    arguments[0]='\0';
    argsCount=0;
}

bool proceedCurrentScript=true;
bool errorBreaker=false;

struct bookmark{
    int name=-1;
    streampos hook;
};

class RattishScriptExecutor{
    //Ratatouille* mainUnit=NULL;
    ifstream ratFile;
    char *path;
    queue<bookmark> codeLabels;
    public:
        RattishScriptExecutor *iterationHook=NULL;
        RattishScriptExecutor(char *path){
            setPath(path);
        }
        RattishScriptExecutor(char *path, RattishScriptExecutor *parrental){
            iterationHook=parrental;
            setPath(path);
        }
        bool isInQueue(int label){
            int queueSize=codeLabels.size();
            while(queueSize--){
                if(codeLabels.front().name==label)return true;
                codeLabels.push(codeLabels.front());
                codeLabels.pop();
            }
            return false;
        }
        void markPointInScript(int label){
            if(isInQueue(label)){
                codeLabels.pop();
            }
            codeLabels.push({label, ratFile.tellg()});
        }
        bool gotoPointInScript(int label){
            if(isInQueue(label)){
                ratFile.seekg(codeLabels.front().hook);
                return true;
            }else return false;
        }
        bool isRatExt(char *path){
            int i=0;
            while(*(path)!='\0'){
                path++;
                i++;
            }
            if(i>4) return
                *(path-1)=='t'
                &&*(path-2)=='a'
                &&*(path-3)=='r'
                &&*(path-4)=='.';
            cout<<"short pathy";
            return false;
        }
        void setPath(char *path){
            this->path=new char[255];
            int i=0;
            do{
                this->path[i]=path[i];
            }while(path[i++]!='\0'||i>254);
            this->path[i]='\0';
        }
        bool isOpen(){return ratFile.is_open();}
        bool openScript(){
            //if(!isRatExt(path)){
            //    ratFile.close();
            //    return false;
            //}
            //if(isOpen())return true;
            this->ratFile.open(
                this->path,
                ifstream::in
            );
            if(this->ratFile.is_open()){
                return true;
            }else{
                cout<<"CANT OPEN";
                return false;
            }
        }
        bool readScript(){
            //cout<<" . ";
            char c=0;
            bool waitForCommand=true;
            bool argumentsInput=false;
            while(this->ratFile.get(c)){
            //cout<<" . ";
                if(c=='\n'||c=='\r'){
                    if(waitForCommand) continue;
                    if(argumentsInput){
                        appendArg('\0');
                        return true;
                        //rattishDictionary[tmpCommand]();
                        //cout<<endl;
                    }
                }else if(waitForCommand){
                    currentCommand=c;
                    waitForCommand=false;
                    argumentsInput=true;
                    //}else arguments+=c;
                }else appendArg(c);
            }
            if(this->ratFile.eof()){
                cout<<"READED";
                this->ratFile.close();
                return false;
            }else{
                cout<<"ERROR_EOF NOT FOUND";
            }
            this->ratFile.close();
            return false;
        }
};

RattishScriptExecutor *payloadChain=NULL;

typedef void (*ratCommand) ();//COMMAND CONTAINER STRUCTURE

ratCommand rattishDictionary[256];//ALL COMMAND CONTAINER,

void commentaryBlank(){cout<<"commentary skipping";}

void pointContextToVariable(){
    context=arguments[0];
}

void setContextValue(){
    safeContextProcedure();
    for(int i=0;i<64;i++){
        contextValue[i]=arguments[i];
        if(arguments[i]=='\0')break;
    }
}
void addOrAppend(){
    safeContextProcedure();
    bool appendFlag=false;
    for(int i=0, j=0;i<64;i++){
        if(arguments[j]=='\0'){
            if(appendFlag)contextValue[i]='\0';
            break;
        }
        if(contextValue[i]=='\0'||appendFlag){
            appendFlag=true;
            contextValue[i]=arguments[j++];
        }
    }
}
void substractOrSlice(){
    safeContextProcedure();
    int i=0;
    for(;i<64;i++)if(contextValue[i]=='\0')break;
    int sliceLen=charArrayToInt(arguments);
    if(i>sliceLen)contextValue[i-sliceLen]='\0';
    else contextValue[0]='\0';
}
void multiplyOrGetCharAtIndex(){
    safeContextProcedure();
    int charindex=charArrayToInt(arguments);
    contextValue[0]=contextValue[charindex];
    contextValue[1]='\0';
}
void divideOrGetLength(){
    safeContextProcedure();
    int i=0;
    for(;i<64;i++)if(contextValue[i]=='\0')break;
    int j=intToCharArray(i, contextValue);
    contextValue[j]='\0';
}
void moduloOrReverse(){
    safeContextProcedure();
    int i=0, j=0;
    for(;i<64;i++)if(contextValue[i]=='\0')break;
    j=i;
    char tmp='\0';
    for(i=0;i<j/2;i++){
        tmp=contextValue[i];
        contextValue[i]=contextValue[j-i-1];
        contextValue[j-i-1]=tmp;
    }
}
void copyFromContext(){
    safeContextProcedure();
    //char *contextHook=contextVariable->second;
    char *varHook=getVariable(arguments[0]);
    for(int i=0;i<64;i++){
        varHook[i]=contextValue[i];
        if(contextValue[i]=='\0')break;
    }
}
void copyToContext(){
    safeContextProcedure();
    //char *contextHook=contextVariable->second;
    char *varHook=getVariable(arguments[0]);
    for(int i=0;i<64;i++){
        contextValue[i]=varHook[i];
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
    safeContextProcedure();
    cout<<arguments;
    cin>>contextValue;
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
void importScript(){
    payloadChain=new RattishScriptExecutor(arguments, payloadChain);
    proceedCurrentScript=false;
}

void resetCommandList(){//SET AS DEFAULT ALL POSSIBLE COMMANDS TO COMMENT, to avoid unwanted errors
    for(short int i=0;i<256;i++){
        rattishDictionary[i]=commentaryBlank;
    }
}
void labelOrder(){
    int pointlabel=0;
    for(short int i=0;i<4;i++){
        pointlabel*=256;
        pointlabel+=arguments[i];
    }
    payloadChain->markPointInScript(pointlabel);
}
void jumpToOrderOrExit(){
    int pointlabel=0;
    for(short int i=0;i<4;i++){
        pointlabel*=256;
        pointlabel+=arguments[i];
    }
    errorBreaker=!payloadChain->gotoPointInScript(pointlabel);
}
void conditionalOrder(){
    int pointlabel=0;
    for(short int i=0;i<4;i++){
        pointlabel*=256;
        pointlabel+=arguments[i];
    }
    safeContextProcedure();
    if(contextValue[0]!='0')payloadChain->gotoPointInScript(pointlabel);
}

void ifContextLesserThenVar(){
    char *varHook=getVariable(arguments[0]);
    int varInt=charArrayToInt(varHook);
    int contextInt=charArrayToInt(contextValue);
    if(contextInt<varInt)contextValue[0]='1';
    else contextValue[0]='0';
    contextValue[1]='\0';
}
void ifContextGreaterThenVar(){
    char *varHook=getVariable(arguments[0]);
    int varInt=charArrayToInt(varHook);
    int contextInt=charArrayToInt(contextValue);
    if(contextInt>varInt)contextValue[0]='1';
    else contextValue[0]='0';
    contextValue[1]='\0';
}
void ifContextEqualsVar(){
    char *varHook=getVariable(arguments[0]);
    int varInt=charArrayToInt(varHook);
    int contextInt=charArrayToInt(contextValue);
    if(contextInt==varInt)contextValue[0]='1';
    else contextValue[0]='0';
    contextValue[1]='\0';
}
void ifContextOrVar(){
    char *varHook=getVariable(arguments[0]);
    if(contextValue[0]=='1'||varHook[0]=='1')contextValue[0]='1';
    else contextValue[0]='0';
    contextValue[1]='\0';
}
void ifContextAndVar(){
    char *varHook=getVariable(arguments[0]);
    if(contextValue[0]=='1'&&varHook[0]=='1')contextValue[0]='1';
    else contextValue[0]='0';
    contextValue[1]='\0';
}
void notContext(){
    if(contextValue[0]=='0')contextValue[0]='1';
    else contextValue[0]='0';
    contextValue[1]='\0';
}

void setRattishNamespaces(){
    //using rattishCore::rattishDictionary;
    //using namespace rattishCommands;

  rattishDictionary['<']=print;
  rattishDictionary['>']=read;
  rattishDictionary['"']=wait;
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

  rattishDictionary['\\']=ifContextLesserThenVar;
  rattishDictionary['/']=ifContextGreaterThenVar;
  rattishDictionary[';']=ifContextEqualsVar;
  rattishDictionary['|']=ifContextOrVar;
  rattishDictionary['&']=ifContextAndVar;
  rattishDictionary['~']=notContext;

  /* temporary deprecated
  //rattishDictionary['[']=beginProcedure;
  //rattishDictionary[']']=endProcedure;
  //rattishDictionary['%']=globalEnviromentSwitcher;
    //rattishDictionary['\'']=debugEcho;
    // ( ) , unused
  */

    rattishDictionary['?']=conditionalOrder;
    rattishDictionary['!']=jumpToOrderOrExit;
    rattishDictionary['.']=labelOrder;

    //rattishDictionary['#']=envSwitch;

    rattishDictionary['@']=importScript;

}



int main()
{
    resetCommandList();
    setRattishNamespaces();

    payloadChain=new RattishScriptExecutor("payload.rat");

    do{
        proceedCurrentScript=true;
        if(payloadChain->openScript()){
            while(payloadChain->readScript()){
                //cout<<" . ";
                rattishDictionary[currentCommand]();
                cout<<endl;
                lineReset();
                if(!proceedCurrentScript||errorBreaker)break;
            }
            if(proceedCurrentScript){
                RattishScriptExecutor *tmp=payloadChain;
                payloadChain=payloadChain->iterationHook;
                delete tmp;
            }
        }else{
            RattishScriptExecutor *tmp=payloadChain;
            payloadChain=payloadChain->iterationHook;
            delete tmp;
        }
    }while(payloadChain!=NULL);

    for (map<char,char*>::iterator it=variableStore.begin(); it!=variableStore.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    return 0;
}
