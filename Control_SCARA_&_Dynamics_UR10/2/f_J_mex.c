/* This file was automatically generated by CasADi 3.6.3.
 *  It consists of: 
 *   1) content generated by CasADi runtime: not copyrighted
 *   2) template code copied from CasADi source: permissively licensed (MIT-0)
 *   3) user code: owned by the user
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) f_J_mex_ ## ID
#endif

#include <math.h>
#include <stdio.h>
#include <string.h>
#ifdef MATLAB_MEX_FILE
#include <mex.h>
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_from_mex CASADI_PREFIX(from_mex)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_sq CASADI_PREFIX(sq)
#define casadi_to_mex CASADI_PREFIX(to_mex)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

#ifdef MATLAB_MEX_FILE
casadi_real* casadi_from_mex(const mxArray* p, casadi_real* y, const casadi_int* sp, casadi_real* w) {
  casadi_int nrow, ncol, is_sparse, c, k, p_nrow, p_ncol;
  const casadi_int *colind, *row;
  mwIndex *Jc, *Ir;
  const double* p_data;
  if (!mxIsDouble(p) || mxGetNumberOfDimensions(p)!=2)
    mexErrMsgIdAndTxt("Casadi:RuntimeError",
      "\"from_mex\" failed: Not a two-dimensional matrix of double precision.");
  nrow = *sp++;
  ncol = *sp++;
  colind = sp;
  row = sp+ncol+1;
  p_nrow = mxGetM(p);
  p_ncol = mxGetN(p);
  is_sparse = mxIsSparse(p);
  Jc = 0;
  Ir = 0;
  if (is_sparse) {
    Jc = mxGetJc(p);
    Ir = mxGetIr(p);
  }
  p_data = (const double*)mxGetData(p);
  if (p_nrow==1 && p_ncol==1) {
    casadi_int nnz;
    double v = is_sparse && Jc[1]==0 ? 0 : *p_data;
    nnz = sp[ncol];
    casadi_fill(y, nnz, v);
  } else {
    casadi_int tr = 0;
    if (nrow!=p_nrow || ncol!=p_ncol) {
      tr = nrow==p_ncol && ncol==p_nrow && (nrow==1 || ncol==1);
      if (!tr) mexErrMsgIdAndTxt("Casadi:RuntimeError",
                                 "\"from_mex\" failed: Dimension mismatch. "
                                 "Expected %d-by-%d, got %d-by-%d instead.",
                                 nrow, ncol, p_nrow, p_ncol);
    }
    if (is_sparse) {
      if (tr) {
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]+c*nrow]=0;
        for (c=0; c<p_ncol; ++c)
          for (k=Jc[c]; k<(casadi_int) Jc[c+1]; ++k) w[c+Ir[k]*p_ncol] = p_data[k];
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) y[k] = w[row[k]+c*nrow];
      } else {
        for (c=0; c<ncol; ++c) {
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]]=0;
          for (k=Jc[c]; k<(casadi_int) Jc[c+1]; ++k) w[Ir[k]]=p_data[k];
          for (k=colind[c]; k<colind[c+1]; ++k) y[k]=w[row[k]];
        }
      }
    } else {
      for (c=0; c<ncol; ++c) {
        for (k=colind[c]; k<colind[c+1]; ++k) {
          y[k] = p_data[row[k]+c*nrow];
        }
      }
    }
  }
  return y;
}

#endif

#define casadi_to_double(x) ((double) x)

#ifdef MATLAB_MEX_FILE
mxArray* casadi_to_mex(const casadi_int* sp, const casadi_real* x) {
  casadi_int nrow, ncol, c, k;
#ifndef CASADI_MEX_NO_SPARSE
  casadi_int nnz;
#endif
  const casadi_int *colind, *row;
  mxArray *p;
  double *d;
#ifndef CASADI_MEX_NO_SPARSE
  casadi_int i;
  mwIndex *j;
#endif /* CASADI_MEX_NO_SPARSE */
  nrow = *sp++;
  ncol = *sp++;
  colind = sp;
  row = sp+ncol+1;
#ifndef CASADI_MEX_NO_SPARSE
  nnz = sp[ncol];
  if (nnz!=nrow*ncol) {
    p = mxCreateSparse(nrow, ncol, nnz, mxREAL);
    for (i=0, j=mxGetJc(p); i<=ncol; ++i) *j++ = *colind++;
    for (i=0, j=mxGetIr(p); i<nnz; ++i) *j++ = *row++;
    if (x) {
      d = (double*)mxGetData(p);
      for (i=0; i<nnz; ++i) *d++ = casadi_to_double(*x++);
    }
    return p;
  }
#endif /* CASADI_MEX_NO_SPARSE */
  p = mxCreateDoubleMatrix(nrow, ncol, mxREAL);
  if (x) {
    d = (double*)mxGetData(p);
    for (c=0; c<ncol; ++c) {
      for (k=colind[c]; k<colind[c+1]; ++k) {
        d[row[k]+c*nrow] = casadi_to_double(*x++);
      }
    }
  }
  return p;
}

#endif

#ifndef CASADI_PRINTF
#ifdef MATLAB_MEX_FILE
  #define CASADI_PRINTF mexPrintf
#else
  #define CASADI_PRINTF printf
#endif
#endif

static const casadi_int casadi_s0[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};
static const casadi_int casadi_s1[39] = {6, 6, 0, 3, 9, 15, 21, 27, 30, 0, 1, 3, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 3, 4, 5};

/* f_J:(i0[6])->(o0[6x6,30nz]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a5, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a6, a60, a61, a62, a63, a7, a8, a9;
  a0=1.6394100000000000e-01;
  a1=arg[0]? arg[0][0] : 0;
  a2=cos(a1);
  a3=(a0*a2);
  a4=-6.1199999999999999e-01;
  a5=arg[0]? arg[0][1] : 0;
  a6=cos(a5);
  a7=(a4*a6);
  a8=sin(a1);
  a9=(a7*a8);
  a10=sin(a5);
  a11=(a4*a10);
  a12=6.1232339957367660e-17;
  a13=(a12*a2);
  a14=(a11*a13);
  a9=(a9+a14);
  a14=-5.7230000000000003e-01;
  a15=arg[0]? arg[0][2] : 0;
  a16=cos(a15);
  a17=(a14*a16);
  a18=(a6*a8);
  a19=(a10*a13);
  a18=(a18+a19);
  a19=(a17*a18);
  a20=sin(a15);
  a21=(a14*a20);
  a22=cos(a5);
  a13=(a22*a13);
  a23=sin(a5);
  a8=(a23*a8);
  a13=(a13-a8);
  a8=(a21*a13);
  a19=(a19+a8);
  a9=(a9+a19);
  a3=(a3-a9);
  a9=1.1570000000000000e-01;
  a19=arg[0]? arg[0][3] : 0;
  a8=cos(a19);
  a24=cos(a15);
  a25=(a24*a13);
  a26=sin(a15);
  a27=(a26*a18);
  a25=(a25-a27);
  a27=(a8*a25);
  a28=sin(a19);
  a18=(a16*a18);
  a13=(a20*a13);
  a18=(a18+a13);
  a13=(a28*a18);
  a27=(a27-a13);
  a13=(a12*a2);
  a27=(a27+a13);
  a13=(a9*a27);
  a3=(a3+a13);
  a13=9.2200000000000004e-02;
  a29=arg[0]? arg[0][4] : 0;
  a30=cos(a29);
  a31=(a12*a8);
  a32=(a31*a25);
  a33=(a12*a28);
  a34=(a33*a18);
  a32=(a32-a34);
  a2=(a2-a32);
  a32=(a30*a2);
  a34=sin(a29);
  a35=cos(a19);
  a18=(a35*a18);
  a36=sin(a19);
  a25=(a36*a25);
  a18=(a18+a25);
  a25=(a34*a18);
  a32=(a32+a25);
  a25=(a12*a27);
  a32=(a32+a25);
  a32=(a13*a32);
  a3=(a3+a32);
  if (res[0]!=0) res[0][0]=a3;
  a3=cos(a1);
  a7=(a7*a3);
  a32=sin(a1);
  a25=(a12*a32);
  a11=(a11*a25);
  a7=(a7-a11);
  a11=(a6*a3);
  a37=(a10*a25);
  a11=(a11-a37);
  a37=(a17*a11);
  a25=(a22*a25);
  a3=(a23*a3);
  a25=(a25+a3);
  a3=(a21*a25);
  a37=(a37-a3);
  a7=(a7+a37);
  a0=(a0*a32);
  a7=(a7+a0);
  a0=(a16*a11);
  a37=(a20*a25);
  a0=(a0-a37);
  a37=(a28*a0);
  a25=(a24*a25);
  a11=(a26*a11);
  a25=(a25+a11);
  a11=(a8*a25);
  a37=(a37+a11);
  a11=(a12*a32);
  a37=(a37+a11);
  a11=(a9*a37);
  a7=(a7+a11);
  a11=(a31*a25);
  a3=(a33*a0);
  a11=(a11+a3);
  a32=(a32-a11);
  a11=(a30*a32);
  a0=(a35*a0);
  a25=(a36*a25);
  a0=(a0-a25);
  a25=(a34*a0);
  a11=(a11-a25);
  a25=(a12*a37);
  a11=(a11+a25);
  a11=(a13*a11);
  a7=(a7+a11);
  if (res[0]!=0) res[0][1]=a7;
  a7=cos(a1);
  a11=(a7*a6);
  a25=sin(a1);
  a3=(a12*a25);
  a38=(a3*a10);
  a11=(a11-a38);
  a38=(a11*a16);
  a39=(a7*a23);
  a40=(a3*a22);
  a39=(a39+a40);
  a40=(a39*a20);
  a38=(a38-a40);
  a40=(a38*a35);
  a41=(a11*a26);
  a42=(a39*a24);
  a41=(a41+a42);
  a42=(a41*a36);
  a40=(a40-a42);
  a42=cos(a29);
  a43=(a40*a42);
  a44=(a38*a33);
  a45=(a41*a31);
  a44=(a44+a45);
  a44=(a25-a44);
  a45=sin(a29);
  a46=(a44*a45);
  a43=(a43+a46);
  a46=arg[0]? arg[0][5] : 0;
  a47=cos(a46);
  a48=(a43*a47);
  a49=(a12*a30);
  a50=(a44*a49);
  a51=(a12*a34);
  a52=(a40*a51);
  a50=(a50-a52);
  a52=(a38*a28);
  a53=(a41*a8);
  a52=(a52+a53);
  a25=(a12*a25);
  a52=(a52+a25);
  a50=(a50-a52);
  a52=sin(a46);
  a25=(a50*a52);
  a48=(a48+a25);
  a25=sin(a1);
  a6=(a25*a6);
  a1=cos(a1);
  a53=(a12*a1);
  a54=(a53*a10);
  a6=(a6+a54);
  a54=(a6*a16);
  a55=(a53*a22);
  a23=(a25*a23);
  a55=(a55-a23);
  a23=(a55*a20);
  a54=(a54+a23);
  a23=(a54*a35);
  a56=(a55*a24);
  a57=(a6*a26);
  a56=(a56-a57);
  a57=(a56*a36);
  a23=(a23+a57);
  a57=(a23*a42);
  a58=(a56*a31);
  a59=(a54*a33);
  a58=(a58-a59);
  a58=(a58-a1);
  a59=(a58*a45);
  a57=(a57+a59);
  a59=(a57*a47);
  a60=(a58*a49);
  a61=(a23*a51);
  a60=(a60-a61);
  a61=(a54*a28);
  a62=(a56*a8);
  a61=(a61-a62);
  a1=(a12*a1);
  a61=(a61-a1);
  a60=(a60-a61);
  a61=(a60*a52);
  a59=(a59+a61);
  a61=casadi_sq(a59);
  a1=casadi_sq(a48);
  a61=(a61+a1);
  a48=(a48/a61);
  a1=(a42*a0);
  a62=(a45*a32);
  a1=(a1+a62);
  a1=(a47*a1);
  a32=(a49*a32);
  a0=(a51*a0);
  a32=(a32-a0);
  a32=(a32-a37);
  a32=(a52*a32);
  a1=(a1+a32);
  a1=(a48*a1);
  a59=(a59/a61);
  a61=(a45*a2);
  a32=(a42*a18);
  a61=(a61-a32);
  a61=(a47*a61);
  a2=(a49*a2);
  a18=(a51*a18);
  a2=(a2+a18);
  a2=(a2-a27);
  a2=(a52*a2);
  a61=(a61+a2);
  a61=(a59*a61);
  a1=(a1-a61);
  if (res[0]!=0) res[0][2]=a1;
  a1=cos(a5);
  a61=(a7*a1);
  a2=sin(a5);
  a27=(a3*a2);
  a61=(a61-a27);
  a27=(a24*a61);
  a18=sin(a5);
  a32=(a7*a18);
  a5=cos(a5);
  a37=(a3*a5);
  a32=(a32+a37);
  a37=(a26*a32);
  a27=(a27-a37);
  a37=(a8*a27);
  a0=(a16*a32);
  a62=(a20*a61);
  a0=(a0+a62);
  a62=(a28*a0);
  a37=(a37-a62);
  a62=(a9*a37);
  a63=(a4*a18);
  a7=(a7*a63);
  a4=(a4*a5);
  a3=(a3*a4);
  a7=(a7+a3);
  a32=(a17*a32);
  a61=(a21*a61);
  a32=(a32+a61);
  a7=(a7+a32);
  a62=(a62-a7);
  a7=(a35*a0);
  a32=(a36*a27);
  a7=(a7+a32);
  a32=(a34*a7);
  a27=(a31*a27);
  a0=(a33*a0);
  a27=(a27-a0);
  a0=(a30*a27);
  a32=(a32-a0);
  a0=(a12*a37);
  a32=(a32+a0);
  a32=(a13*a32);
  a62=(a62+a32);
  if (res[0]!=0) res[0][3]=a62;
  a62=(a53*a4);
  a63=(a25*a63);
  a62=(a62-a63);
  a63=(a53*a5);
  a18=(a25*a18);
  a63=(a63-a18);
  a18=(a17*a63);
  a53=(a53*a2);
  a25=(a25*a1);
  a53=(a53+a25);
  a25=(a21*a53);
  a18=(a18-a25);
  a62=(a62+a18);
  a18=(a16*a63);
  a25=(a20*a53);
  a18=(a18-a25);
  a25=(a28*a18);
  a53=(a24*a53);
  a63=(a26*a63);
  a53=(a53+a63);
  a63=(a8*a53);
  a25=(a25+a63);
  a63=(a9*a25);
  a62=(a62+a63);
  a63=(a12*a25);
  a1=(a31*a53);
  a32=(a33*a18);
  a1=(a1+a32);
  a32=(a30*a1);
  a18=(a35*a18);
  a53=(a36*a53);
  a18=(a18-a53);
  a53=(a34*a18);
  a32=(a32+a53);
  a63=(a63-a32);
  a63=(a13*a63);
  a62=(a62+a63);
  if (res[0]!=0) res[0][4]=a62;
  a17=(a17*a5);
  a21=(a21*a2);
  a17=(a17-a21);
  a4=(a4+a17);
  a17=(a16*a5);
  a21=(a20*a2);
  a17=(a17-a21);
  a21=(a28*a17);
  a2=(a24*a2);
  a5=(a26*a5);
  a2=(a2+a5);
  a5=(a8*a2);
  a21=(a21+a5);
  a5=(a9*a21);
  a4=(a4+a5);
  a5=(a12*a21);
  a62=(a31*a2);
  a63=(a33*a17);
  a62=(a62+a63);
  a63=(a30*a62);
  a17=(a35*a17);
  a2=(a36*a2);
  a17=(a17-a2);
  a2=(a34*a17);
  a63=(a63+a2);
  a5=(a5-a63);
  a63=(a13*a5);
  a4=(a4+a63);
  if (res[0]!=0) res[0][5]=a4;
  a4=(a42*a18);
  a63=(a45*a1);
  a4=(a4-a63);
  a4=(a47*a4);
  a1=(a49*a1);
  a18=(a51*a18);
  a1=(a1+a18);
  a1=(a1+a25);
  a1=(a52*a1);
  a4=(a4-a1);
  a4=(a48*a4);
  a1=(a51*a7);
  a25=(a49*a27);
  a1=(a1-a25);
  a1=(a1-a37);
  a1=(a52*a1);
  a7=(a42*a7);
  a27=(a45*a27);
  a7=(a7+a27);
  a7=(a47*a7);
  a1=(a1-a7);
  a1=(a59*a1);
  a4=(a4-a1);
  if (res[0]!=0) res[0][6]=a4;
  a4=(a42*a17);
  a1=(a45*a62);
  a4=(a4-a1);
  a1=(a47*a4);
  a62=(a49*a62);
  a17=(a51*a17);
  a62=(a62+a17);
  a62=(a62+a21);
  a21=(a52*a62);
  a1=(a1-a21);
  a21=1.;
  a16=(a10*a16);
  a20=(a22*a20);
  a16=(a16+a20);
  a20=(a16*a35);
  a24=(a22*a24);
  a26=(a10*a26);
  a24=(a24-a26);
  a26=(a24*a36);
  a20=(a20+a26);
  a26=(a20*a42);
  a17=(a24*a31);
  a7=(a16*a33);
  a17=(a17-a7);
  a17=(a17+a12);
  a7=(a17*a45);
  a26=(a26+a7);
  a7=(a26*a47);
  a27=(a17*a49);
  a37=(a20*a51);
  a27=(a27-a37);
  a37=(a16*a28);
  a25=(a24*a8);
  a37=(a37-a25);
  a25=3.7493994566546440e-33;
  a37=(a37+a25);
  a27=(a27-a37);
  a25=(a27*a52);
  a7=(a7+a25);
  a7=casadi_sq(a7);
  a21=(a21-a7);
  a21=sqrt(a21);
  a1=(a1/a21);
  a1=(-a1);
  if (res[0]!=0) res[0][7]=a1;
  a1=(a17*a30);
  a7=(a20*a34);
  a1=(a1-a7);
  a37=(a12*a37);
  a1=(a1+a37);
  a37=cos(a46);
  a7=(a27*a37);
  a25=sin(a46);
  a18=(a26*a25);
  a7=(a7-a18);
  a18=casadi_sq(a7);
  a63=casadi_sq(a1);
  a18=(a18+a63);
  a1=(a1/a18);
  a62=(a37*a62);
  a4=(a25*a4);
  a62=(a62+a4);
  a62=(a1*a62);
  a7=(a7/a18);
  a5=(a7*a5);
  a62=(a62+a5);
  a62=(-a62);
  if (res[0]!=0) res[0][8]=a62;
  a62=cos(a15);
  a5=(a11*a62);
  a18=sin(a15);
  a4=(a39*a18);
  a5=(a5-a4);
  a4=(a8*a5);
  a63=sin(a15);
  a2=(a11*a63);
  a15=cos(a15);
  a32=(a39*a15);
  a2=(a2+a32);
  a32=(a28*a2);
  a4=(a4-a32);
  a32=(a9*a4);
  a53=(a14*a63);
  a11=(a11*a53);
  a14=(a14*a15);
  a39=(a39*a14);
  a11=(a11+a39);
  a32=(a32-a11);
  a11=(a35*a2);
  a39=(a36*a5);
  a11=(a11+a39);
  a39=(a34*a11);
  a5=(a31*a5);
  a2=(a33*a2);
  a5=(a5-a2);
  a2=(a30*a5);
  a39=(a39-a2);
  a2=(a12*a4);
  a39=(a39+a2);
  a39=(a13*a39);
  a32=(a32+a39);
  if (res[0]!=0) res[0][9]=a32;
  a32=(a55*a14);
  a39=(a6*a53);
  a32=(a32-a39);
  a39=(a55*a15);
  a2=(a6*a63);
  a39=(a39-a2);
  a2=(a28*a39);
  a55=(a55*a18);
  a6=(a6*a62);
  a55=(a55+a6);
  a6=(a8*a55);
  a2=(a2+a6);
  a6=(a9*a2);
  a32=(a32+a6);
  a6=(a12*a2);
  a0=(a31*a55);
  a61=(a33*a39);
  a0=(a0+a61);
  a61=(a30*a0);
  a39=(a35*a39);
  a55=(a36*a55);
  a39=(a39-a55);
  a55=(a34*a39);
  a61=(a61+a55);
  a6=(a6-a61);
  a6=(a13*a6);
  a32=(a32+a6);
  if (res[0]!=0) res[0][10]=a32;
  a14=(a22*a14);
  a53=(a10*a53);
  a14=(a14-a53);
  a15=(a22*a15);
  a63=(a10*a63);
  a15=(a15-a63);
  a28=(a28*a15);
  a22=(a22*a18);
  a10=(a10*a62);
  a22=(a22+a10);
  a8=(a8*a22);
  a28=(a28+a8);
  a8=(a9*a28);
  a14=(a14+a8);
  a8=(a12*a28);
  a31=(a31*a22);
  a33=(a33*a15);
  a31=(a31+a33);
  a33=(a30*a31);
  a35=(a35*a15);
  a36=(a36*a22);
  a35=(a35-a36);
  a36=(a34*a35);
  a33=(a33+a36);
  a8=(a8-a33);
  a33=(a13*a8);
  a14=(a14+a33);
  if (res[0]!=0) res[0][11]=a14;
  a14=(a42*a39);
  a33=(a45*a0);
  a14=(a14-a33);
  a14=(a47*a14);
  a0=(a49*a0);
  a39=(a51*a39);
  a0=(a0+a39);
  a0=(a0+a2);
  a0=(a52*a0);
  a14=(a14-a0);
  a14=(a48*a14);
  a0=(a51*a11);
  a2=(a49*a5);
  a0=(a0-a2);
  a0=(a0-a4);
  a0=(a52*a0);
  a11=(a42*a11);
  a5=(a45*a5);
  a11=(a11+a5);
  a11=(a47*a11);
  a0=(a0-a11);
  a0=(a59*a0);
  a14=(a14-a0);
  if (res[0]!=0) res[0][12]=a14;
  a14=(a42*a35);
  a0=(a45*a31);
  a14=(a14-a0);
  a0=(a47*a14);
  a31=(a49*a31);
  a35=(a51*a35);
  a31=(a31+a35);
  a31=(a31+a28);
  a28=(a52*a31);
  a0=(a0-a28);
  a0=(a0/a21);
  a0=(-a0);
  if (res[0]!=0) res[0][13]=a0;
  a31=(a37*a31);
  a14=(a25*a14);
  a31=(a31+a14);
  a31=(a1*a31);
  a8=(a7*a8);
  a31=(a31+a8);
  a31=(-a31);
  if (res[0]!=0) res[0][14]=a31;
  a31=cos(a19);
  a8=(a38*a31);
  a14=sin(a19);
  a0=(a41*a14);
  a8=(a8-a0);
  a0=(a9*a8);
  a28=sin(a19);
  a35=(a38*a28);
  a19=cos(a19);
  a11=(a41*a19);
  a35=(a35+a11);
  a11=(a34*a35);
  a5=(a12*a31);
  a38=(a38*a5);
  a4=(a12*a14);
  a41=(a41*a4);
  a38=(a38-a41);
  a41=(a30*a38);
  a11=(a11-a41);
  a41=(a12*a8);
  a11=(a11+a41);
  a11=(a13*a11);
  a0=(a0+a11);
  if (res[0]!=0) res[0][15]=a0;
  a0=(a54*a31);
  a11=(a56*a14);
  a0=(a0+a11);
  a11=(a9*a0);
  a41=(a12*a0);
  a2=(a56*a4);
  a39=(a54*a5);
  a2=(a2+a39);
  a39=(a30*a2);
  a56=(a56*a19);
  a54=(a54*a28);
  a56=(a56-a54);
  a54=(a34*a56);
  a39=(a39+a54);
  a41=(a41-a39);
  a41=(a13*a41);
  a11=(a11+a41);
  if (res[0]!=0) res[0][16]=a11;
  a31=(a16*a31);
  a14=(a24*a14);
  a31=(a31+a14);
  a9=(a9*a31);
  a14=(a12*a31);
  a4=(a24*a4);
  a5=(a16*a5);
  a4=(a4+a5);
  a30=(a30*a4);
  a24=(a24*a19);
  a16=(a16*a28);
  a24=(a24-a16);
  a34=(a34*a24);
  a30=(a30+a34);
  a14=(a14-a30);
  a30=(a13*a14);
  a9=(a9+a30);
  if (res[0]!=0) res[0][17]=a9;
  a9=(a42*a56);
  a30=(a45*a2);
  a9=(a9-a30);
  a9=(a47*a9);
  a2=(a49*a2);
  a56=(a51*a56);
  a2=(a2+a56);
  a2=(a2+a0);
  a2=(a52*a2);
  a9=(a9-a2);
  a9=(a48*a9);
  a2=(a51*a35);
  a0=(a49*a38);
  a2=(a2-a0);
  a2=(a2-a8);
  a2=(a52*a2);
  a35=(a42*a35);
  a38=(a45*a38);
  a35=(a35+a38);
  a35=(a47*a35);
  a2=(a2-a35);
  a2=(a59*a2);
  a9=(a9-a2);
  if (res[0]!=0) res[0][18]=a9;
  a42=(a42*a24);
  a45=(a45*a4);
  a42=(a42-a45);
  a45=(a47*a42);
  a49=(a49*a4);
  a51=(a51*a24);
  a49=(a49+a51);
  a49=(a49+a31);
  a31=(a52*a49);
  a45=(a45-a31);
  a45=(a45/a21);
  a45=(-a45);
  if (res[0]!=0) res[0][19]=a45;
  a49=(a37*a49);
  a42=(a25*a42);
  a49=(a49+a42);
  a49=(a1*a49);
  a14=(a7*a14);
  a49=(a49+a14);
  a49=(-a49);
  if (res[0]!=0) res[0][20]=a49;
  a49=sin(a29);
  a14=(a44*a49);
  a42=cos(a29);
  a45=(a40*a42);
  a14=(a14+a45);
  a14=(a13*a14);
  a14=(-a14);
  if (res[0]!=0) res[0][21]=a14;
  a14=(a58*a49);
  a45=(a23*a42);
  a14=(a14+a45);
  a14=(a13*a14);
  a14=(-a14);
  if (res[0]!=0) res[0][22]=a14;
  a14=(a17*a49);
  a45=(a20*a42);
  a14=(a14+a45);
  a13=(a13*a14);
  a13=(-a13);
  if (res[0]!=0) res[0][23]=a13;
  a13=cos(a29);
  a45=(a58*a13);
  a29=sin(a29);
  a31=(a23*a29);
  a45=(a45-a31);
  a45=(a47*a45);
  a49=(a12*a49);
  a58=(a58*a49);
  a12=(a12*a42);
  a23=(a23*a12);
  a58=(a58+a23);
  a58=(a52*a58);
  a45=(a45-a58);
  a45=(a48*a45);
  a58=(a44*a13);
  a23=(a40*a29);
  a58=(a58-a23);
  a58=(a47*a58);
  a44=(a44*a49);
  a40=(a40*a12);
  a44=(a44+a40);
  a44=(a52*a44);
  a58=(a58-a44);
  a58=(a59*a58);
  a45=(a45-a58);
  if (res[0]!=0) res[0][24]=a45;
  a13=(a17*a13);
  a29=(a20*a29);
  a13=(a13-a29);
  a47=(a47*a13);
  a17=(a17*a49);
  a20=(a20*a12);
  a17=(a17+a20);
  a52=(a52*a17);
  a47=(a47-a52);
  a47=(a47/a21);
  a47=(-a47);
  if (res[0]!=0) res[0][25]=a47;
  a7=(a7*a14);
  a37=(a37*a17);
  a25=(a25*a13);
  a37=(a37+a25);
  a37=(a1*a37);
  a7=(a7-a37);
  if (res[0]!=0) res[0][26]=a7;
  a7=cos(a46);
  a60=(a60*a7);
  a37=sin(a46);
  a57=(a57*a37);
  a60=(a60-a57);
  a48=(a48*a60);
  a50=(a50*a7);
  a43=(a43*a37);
  a50=(a50-a43);
  a59=(a59*a50);
  a48=(a48-a59);
  if (res[0]!=0) res[0][27]=a48;
  a7=(a27*a7);
  a37=(a26*a37);
  a7=(a7-a37);
  a7=(a7/a21);
  a7=(-a7);
  if (res[0]!=0) res[0][28]=a7;
  a7=sin(a46);
  a27=(a27*a7);
  a46=cos(a46);
  a26=(a26*a46);
  a27=(a27+a26);
  a1=(a1*a27);
  a1=(-a1);
  if (res[0]!=0) res[0][29]=a1;
  return 0;
}

CASADI_SYMBOL_EXPORT int f_J(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int f_J_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int f_J_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void f_J_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int f_J_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void f_J_release(int mem) {
}

CASADI_SYMBOL_EXPORT void f_J_incref(void) {
}

CASADI_SYMBOL_EXPORT void f_J_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int f_J_n_in(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_int f_J_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real f_J_default_in(casadi_int i) {
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* f_J_name_in(casadi_int i) {
  switch (i) {
    case 0: return "i0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* f_J_name_out(casadi_int i) {
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* f_J_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* f_J_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int f_J_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 1;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

#ifdef MATLAB_MEX_FILE
void mex_f_J(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  casadi_int i;
  int mem;
  casadi_real w[100];
  casadi_int *iw = 0;
  const casadi_real* arg[1] = {0};
  casadi_real* res[1] = {0};
  if (argc>1) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"f_J\" failed. Too many input arguments (%d, max 1)", argc);
  if (resc>1) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"f_J\" failed. Too many output arguments (%d, max 1)", resc);
  if (--argc>=0) arg[0] = casadi_from_mex(argv[0], w, casadi_s0, w+36);
  --resc;
  res[0] = w+6;
  f_J_incref();
  mem = f_J_checkout();
  i = f_J(arg, res, iw, w+36, mem);
  if (i) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"f_J\" failed.");
  f_J_release(mem);
  f_J_decref();
  if (res[0]) resv[0] = casadi_to_mex(casadi_s1, res[0]);
}
#endif

casadi_int main_f_J(casadi_int argc, char* argv[]) {
  casadi_int j;
  casadi_real* a;
  const casadi_real* r;
  casadi_int flag;
  casadi_int *iw = 0;
  casadi_real w[100];
  const casadi_real* arg[1];
  casadi_real* res[1];
  arg[0] = w+0;
  res[0] = w+6;
  a = w;
  for (j=0; j<6; ++j) if (scanf("%lg", a++)<=0) return 2;
  flag = f_J(arg, res, iw, w+36, 0);
  if (flag) return flag;
  r = w+6;
  for (j=0; j<30; ++j) CASADI_PRINTF("%g ", *r++);
  CASADI_PRINTF("\n");
  return 0;
}


#ifdef MATLAB_MEX_FILE
void mexFunction(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  char buf[4];
  int buf_ok = argc > 0 && !mxGetString(*argv, buf, sizeof(buf));
  if (!buf_ok) {
    mex_f_J(resc, resv, argc, argv);
    return;
  } else if (strcmp(buf, "f_J")==0) {
    mex_f_J(resc, resv, argc-1, argv+1);
    return;
  }
  mexErrMsgTxt("First input should be a command string. Possible values: 'f_J'");
}
#endif
CASADI_SYMBOL_EXPORT int main(int argc, char* argv[]) {
  if (argc<2) {
    /* name error */
  } else if (strcmp(argv[1], "f_J")==0) {
    return main_f_J(argc-2, argv+2);
  }
  fprintf(stderr, "First input should be a command string. Possible values: 'f_J'\nNote: you may use function.generate_input to create a command string.\n");
  return 1;
}
#ifdef __cplusplus
} /* extern "C" */
#endif
