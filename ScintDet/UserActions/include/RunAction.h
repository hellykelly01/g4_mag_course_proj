#ifndef RUN_ACTION_H
#define RUN_ACTION_H

#include "G4UserRunAction.hh"
#include <string>

class RunAction : public G4UserRunAction{
public:

  RunAction(const std::string& fileName);
  ~RunAction();
  void BeginOfRunAction(const G4Run*) override;
  void EndOfRunAction(const G4Run*) override;
  void SetHistName(const std::string& name){ histName = name; }
private:
  std::string histName;
};

#endif // RUN_ACTION_H
