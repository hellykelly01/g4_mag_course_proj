#include "TrackingAction.h"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"


void TrackingAction::PostUserTrackingAction(const G4Track* aTrack){
  if(aTrack->GetParentID() == 0 && aTrack->GetTrackStatus() == G4TrackStatus::fStopAndKill){

    auto EvtId =  G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    auto time = aTrack->GetGlobalTime() * 1000000 / second;
    std::cout << "EvtId: " << EvtId << " -> primary particle lifespan: " << time << std::endl;

    auto *manager = G4AnalysisManager::Instance();
    auto lastNtupleId = manager->GetNofNtuples() - 1;
    manager->FillNtupleDColumn(lastNtupleId, 0, time);
    manager->AddNtupleRow(lastNtupleId);
  }

}