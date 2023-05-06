#include "synch.h"
#include "pcb.h"

PCB::PCB(int id) {
    this->processID = kernel->currentThread->processID;
    joinsem = new Semaphore("joinsem", 0);
    exitsem = new Semaphore("exitsem", 0);
    multex = new Semaphore("multex", 1);
}

PCB::~PCB() {
    delete joinsem;
    delete exitsem;
    delete multex;

    if (thread) {
        thread->FreeSpace();
        thread->Finish();
    }

    delete[] filename;
}

void StartProcess(void* pid) {
    int id;
    id = *((int*)pid);

    char* fileName = kernel->pTab->GetFileName(id);

    AddrSpace* space;
    space = new AddrSpace(fileName);

    if (space == NULL) {
        printf("\nPCB::Exec: Can't create AddSpace.");
        return;
    }

    space->Execute();
    
    ASSERT(FALSE);  
}

int PCB::Exec(char* filename, int id) {
   
    multex->P();

    this->thread = new Thread(filename, true);
    if (this->thread == NULL) {
        printf("\nPCB::Exec: Not enough memory!\n");
        multex->V();  
        return -1;   
    }


    this->thread->processID = id;
    this->parentID = kernel->currentThread->processID;
    this->thread->Fork(StartProcess, &this->thread->processID);

    multex->V();
    return id;
}

int PCB::GetID() { return thread->processID; }

int PCB::GetNumWait() { return numwait; }

void PCB::JoinWait() { joinsem->P(); }

void PCB::ExitWait() { exitsem->P(); }

void PCB::JoinRelease() { joinsem->V(); }

void PCB::ExitRelease() { exitsem->V(); }

void PCB::IncNumWait() {
    multex->P();
    ++numwait;
    multex->V();
}

void PCB::DecNumWait() {
    multex->P();
    if (numwait > 0) --numwait;
    multex->V();
}

void PCB::SetExitCode(int code) { exitcode = code; }

int PCB::GetExitCode() { return exitcode; }

void PCB::SetFileName(char* name) { strcpy(filename, name); }

char* PCB::GetFileName() { return filename; }