#include "G4AnalysisManager.hh"

#include "RunAction.h"

RunAction::RunAction(const std::string& fileName){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->OpenFile(fileName.c_str());
}

void RunAction::BeginOfRunAction(const G4Run *run){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->CreateNtuple(histName.c_str(), histName.c_str());
    manager->CreateNtupleDColumn(histName.c_str());
    manager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run *run){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
   // manager->Write();
}

RunAction::~RunAction(){
    G4AnalysisManager *manager = G4AnalysisManager::Instance();
    manager->Write();
    manager->CloseFile();

}