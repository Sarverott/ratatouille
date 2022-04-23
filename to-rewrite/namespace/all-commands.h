#include "../rattish-core.h"
#include "./basic.h"
#include "./variables.h"
#include "./logics.h"
#include "./mechanics.h"
#include "./procedures.h"

void setRattishNamespaces(){
    using rattishCore::rattishDictionary;
    using namespace rattishCommands;
  //rattishDictionary['#']=commentaryBlank;

  //rattishDictionary['<']=printOutput;
  //rattishDictionary['>']=readInput;
  //rattishDictionary['.']=waitTimePause;
  //rattishDictionary['_']=pressKeyS;
  //rattishDictionary['^']=releaseKeyS;

  //rattishDictionary['$']=pointContextToVar;
  //rattishDictionary['=']=setContextValue;
  //rattishDictionary['+']=addToContext;
  //rattishDictionary['-']=subToContext;
  //rattishDictionary['*']=mulToContext;
  //rattishDictionary[':']=divToContext;
  //rattishDictionary['}']=copyFromContextToVar;
  //rattishDictionary['{']=copyFromVarToContext;

  //rattishDictionary['\\']=ifContextLesserThenVar;
  //rattishDictionary['/']=ifContextGreaterThenVar;
  //rattishDictionary['|']=ifContextEqualsVar;
  //rattishDictionary[';']=ifContextOrVar;
  //rattishDictionary['&']=ifContextAndVar;
  //rattishDictionary['~']=notContext;

  /*
  rattishDictionary['[']=beginProcedure;
  rattishDictionary[']']=endProcedure;
  rattishDictionary['%']=callProcedure;
  */

  //rattishDictionary['?']=beginIfConditionBlock;

  /*
  rattishDictionary['!']=endIfConditionBlock;
  */

  //rattishDictionary['@']=importScriptFile;

  //rattishDictionary['"']=globalEnviromentSwitcher;
  //rattishDictionary['\'']=debugEcho;
}
