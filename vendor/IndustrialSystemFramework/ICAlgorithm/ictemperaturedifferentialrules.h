#ifndef ICTEMPERATUREDIFFERENTIALRULES_H
#define ICTEMPERATUREDIFFERENTIALRULES_H

#include "ICAlgorithm_global.h"
#include "icfuzzyrules.h"

class ICALGORITHMSHARED_EXPORT ICTemperatureDifferentialRules : public ICFuzzyRules
{
public:
    ICTemperatureDifferentialRules();
    virtual LinguisticVar Interpret(LinguisticVar* vars, int size) const
    {
        Q_ASSERT_X(size > 0, "ICTemperatureProportionRules::Interpret", "wrong size");
        if(size < 2)
        {
            return varTable_[LinguisticVarInLevel(LL_Medium, vars[0])][3];
        }
        return varTable_[LinguisticVarInLevel(LL_Medium, vars[0])][LinguisticVarInLevel(LL_Medium, vars[1])];
    }
private:
    static LinguisticVar varTable_[7][7];
};

#endif // ICTEMPERATUREDIFFERENTIALRULES_H
