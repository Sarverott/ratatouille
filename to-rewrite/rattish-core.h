//RATTISH DECLARATION CORE SEEDER - ratatouille implementation
//part of rattish language project
//Sett Sarverott @ 2022

#ifndef RATTISH_CORE_FLAG
#define RATTISH_CORE_FLAG 1

#define RATTISH_STREAMERS_COUNT 64
#define RATTISH_PAYLOAD_PATH "payload.rat"

namespace rattishCore{
/*
** INTERPRETER DECLARATOR
*/
    typedef int (*ratCommand) (char* arguments);//COMMAND CONTAINER STRUCTURE

    ratCommand rattishDictionary[256];//ALL COMMAND CONTAINER,
    int commentaryBlank(char* arguments){return 0;}//COMMENTARY ACTION DO NOTHING
    void resetCommandList(){//SET AS DEFAULT ALL POSSIBLE COMMANDS TO COMMENT, to avoid unwanted errors
        for(short int i=0;i<256;i++){
            rattishDictionary[i]=commentaryBlank;
        }
    }

/*
** STREAM STRUCTURES
*/
    typedef char (*ratIOStream) (char buffer);

    ratIOStream
        ratReaders[RATTISH_STREAMERS_COUNT],
        ratWriters[RATTISH_STREAMERS_COUNT];

    char streamDeadEnds(char d){return 0;}
    void resetStreamsEnds(){//SET AS DEFAULT ALL POSSIBLE COMMANDS TO COMMENT, to avoid unwanted errors
        for(
            short int i=0;
            i<RATTISH_STREAMERS_COUNT;
            i++
        ){
            ratRead[i]=streamDeadEnds;
            ratWrite[i]=streamDeadEnds;
        }
    }
}
/*
enum sewerStreamSelector{
    shell,
    payload,
    file,
    variable//,

    //keyboard,
    //mouse,
    //serialport,
    //printer,

    //tcp,
    //ftp,
    //smtp,
    //ssh,

    //speechRecognizeSynth,
    //brailinterface,

};
 char ratShellInput(char d){
    return 0;
 }
 char ratShellOutput(char d){
    return 0;
 }
*/
#endif // RATTISH_CORE_FLAG
