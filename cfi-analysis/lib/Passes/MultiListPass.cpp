/*
 * TODO: Comments
 */

#include "cfi/MultiListPass.h"

#include "dsa/CallTargets.h"
#include "dsa/DSGraph.h"
#include "dsa/DSCallGraph.h"

using namespace llvm;

namespace cfi {

    MultiListPass::MultiListPass(Module &M) : MultiPass(M){}
    /*
     * Generate a unique ID for each target
     */
    void MultiListPass::generateDestIDs()
    {
        genIDs(jmpDestMap, jmpIdMap, jmpIdCounts, jmpMergedMap);
        genIDs(retDestMap, retIdMap, retIdCounts, retMergedMap);
    }


    void MultiListPass::genIDs(InstDestMap &destMap, InstIDMap &idMap, std::map<int,int> &idCounts, InstDestMap &mergedMap)
    { 
        InstSet targetSet;

        InstDestMap::iterator MB, ME;
        /* create a set of target instructions */
        for (MB = destMap.begin(), ME = destMap.end(); MB != ME; MB++)
        {
            Instruction* I = MB->first;
            InstSet mset = MB->second;
            mergedMap[I] = mset;
            InstSet::iterator LB, LE;
            /* for each target of this callsite, add to set */
            for (LB = mset.begin(), LE = mset.end(); LB != LE; LB++)
            {
                Instruction *inst = *LB;
                targetSet.insert(inst);
            }
        }
        
        //generate ID for each set in setList, then add each Instr
        //and their ID to idMap
        InstSet::iterator LB, LE;
        for (LB = targetSet.begin(), LE = targetSet.end(); LB != LE; LB++)
        {
            int ID = rand() % MAX;
            Instruction* K = *LB;
            idMap[K] = ID;
            idCounts[ID] = 1;
        }
    }
}