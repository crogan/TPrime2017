#ifndef TPrimeOptimization_h
#define TPrimeOptimization_h

#include "OptimizationBase.hh"
#include "ReducedBase.hh"

class TPrimeOptimization : public OptimizationBase<ReducedBase> {

public:
  TPrimeOptimization();
  virtual ~TPrimeOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
