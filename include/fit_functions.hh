#ifndef FIT_FUNCTIONS_h
#define FIT_FUNCTIONS_h

#include <cmath>
#include <iostream>

// Normal distribution
double Normal(double x, double N, double mu, double sg){
  double pi = acos(-1.);
  double G = exp(-pow((x - mu),2) / (2 * pow(sg,2))) / (sqrt(2 * pi) * sg);
  return N * G;
}

double Gaus(double* xs, double* par){
  return Normal(xs[0], par[0], par[1], par[2]);
}

double DoubleGaus(double* xs, double* par){
  double G0 = Normal(xs[0], par[0], par[4]+par[1], par[2]);
  double G1 = Normal(xs[0], par[3], par[4], par[5]);
  return G0 + G1;
}

double GausExp(double* xs, double* par){
  Float_t xx = xs[0];

  double S = par[0];
  double mu = par[1];
  double sig1 = par[2];
  double sig2 = par[3];
  double A = par[4];

  double tran = mu+fabs(S)*sig2*sig2;

  if(xx > tran){
    return A*(exp(S*xx));
  } else {
    double Agaus = A*(exp(S*tran))*exp((tran-mu)*(tran-mu)/(2.*sig2*sig2));
    if(xx > mu){
      return Agaus*exp(-(xx-mu)*(xx-mu)/(2.*sig2*sig2));
    } else {
      return Agaus*exp(-(xx-mu)*(xx-mu)/(2.*sig1*sig1));
    }
  }

}

double GausExpN(double* xs, double* par){
  Float_t xx = xs[0];

  double S = par[0];
  double mu = par[1];
  double sig1 = par[2];
  double sig2 = par[3];
  double A = par[4];
  double n = par[5]; // extra parameter

  //
  // Calculate transition point
  // w/ Newton-Raphson
  
  // starting guess (n = 1)
  double tran = mu+fabs(S)*sig2*sig2;
  double f  = 0.;
  double df = 1.;
  double dt = 0.;
  int count = 0;

  while(fabs(df) > 1e-10 && count < 100){
    f  = n*fabs(S)*sig2*sig2*pow(tran, n-1.) + mu - tran;
    df = n*(n-1.)*sig2*sig2*fabs(S)*pow(tran, n-2.) - 1.;
    dt = f/df;
    tran -= dt;
    //std::cout << tran << " " << df << " " << count << std::endl;
    count++;
  }

  if(xx > tran){
    return A*(exp(S*pow(xx,n)));
  } else {
    double Agaus = A*(exp(S*pow(tran,n)))*exp((tran-mu)*(tran-mu)/(2.*sig2*sig2));
    if(xx > mu){
      return Agaus*exp(-(xx-mu)*(xx-mu)/(2.*sig2*sig2));
    } else {
      return Agaus*exp(-(xx-mu)*(xx-mu)/(2.*sig1*sig1));
    }
  }

}

double DoubleGaus_SameNorm(double* xs, double* par){
  double G0 = Normal(xs[0], par[0], par[3]+par[1], par[2]);
  double G1 = Normal(xs[0], par[0], par[3], par[4]);
  return G0 + G1;
}

double P0_P2_P1(double* xs, double* par){
  double x = xs[0];

  double c0 = par[0];
  double A2 = par[1];
  double t02 = par[2];
  double d21 = par[3];

  if(x < t02)
    return c0;
  if(x < t02+d21)
    return c0 + A2*(x-t02)*(x-t02);

  return c0 + A2*d21*(2.*x - d21 - 2*t02);
}

double P1_P2_P0(double* xs, double* par){
  double x = xs[0];

  double c0 = par[0];
  double A2 = par[1];
  double t02 = par[2];
  double d21 = par[3];
 
  if(x > t02)
    return c0;
  if(x > t02+d21)
    return c0 + A2*(x-t02)*(x-t02);

  return c0 + A2*d21*(2.*x - d21 - 2*t02);
}

double P1(double* xs, double* par){
  double x = xs[0];

  double c = par[0];
  double m = par[1];
  
  return m*x+c;
}

double TurnOn(double* xs, double* par){
  double x = xs[0];

  double a = par[0];
  double b = par[1];
  double C = par[2];

  if(x > a && x < a+b)
    return C;
  else
    return 0;
}

#endif
