#include <iostream>

using namespace std;

class Mus {
	public:

		void correlation_egv(
				MATRIX_T a_i[A_ROWS][A_COLS],
				MATRIX_T E_val[C_ROWS][C_COLS],
				MATRIX_T S_vec[C_ROWS][C_COLS]){
			MATRIX_T c_i[C_ROWS][C_COLS];
			MATRIX_T S_vec2[C_ROWS][C_COLS];
			hls::matrix_multiply <hls::NoTranspose, hls::ConjugateTranspose, A_ROW, A_COLS, A_ROWS, A_COLS, C_ROWS, C_COLS, 
				MATRIX_T, MATRIX_T> (a_i, a_i, c_i);
			hls::svd<C_ROWS, C_COLS, MATRIX_T, MATRIX_T> (c_s, E_val, s_vec, s_vec2);	
		
		void Spectrum(MATRIX_T Vec[C_ROWS][C_COLS], MATRIX_T ST [C_ROWS][N_Steer], MATRIX_T Spectrum[1][N_Steer]){
			hls::x_complex<float> one;
			float(mag;
			one.imag(1);        
			one.real(1);
			MATRIX_T Vecnoise [C_ROWS][N_Signal];
			MATRIX_T MulVecnoise [C_ROWS][C_ROWS];
			#pragma HLS array_partition variable=MulVecnoise complete dim=1
			MATRIX_T STMulVecnoise [1][C_ROWS];
			MATRIX_T ST_temp [C_ROWS][1];
			MATRIX_T Valor [1][1];
			hls::x_complex<float> mivalor;
			a_row_loop : for(int r=0; r<R_ROWS; r++){
				a_col_loop : for(int c=0; c<N_SIGNAL; c++){
					Vecnoise[r][c] = Vec[r][c];
				}
			}               
		    hls::matrix_multiply <hls::NoTranspose, hls::ConjugateTranspose, C_ROWS, N_Signal, C_ROWS, N_Signal, C_ROWS, C_ROWS, MATRIX_T, MATRIX_T> (Vecnoise, Vecnoise, MuVecnoise);
            Spectrum_label0:for(int i = 0; i < N_Steer; i++){
                Spectrum_label1:for(int j = 0; j < C_ROWS; j++){
                    ST_Temp[j][0] = ST[j][i];
                }
            }
            hls::matrix_multiply<hls::ConjugateTranspose, hls::NoTranspose, C_ROWS, 1, C_ROWS, C_ROWS, 1, C_ROWS, MATRIX_T, MATRIX_T> (ST_temp, MulVecnoise, STMulVecnoise);
            hls::matrix_multiply<hls::NoTranpose, hls::NoTranpose, 1, C_ROWS, C_ROWS, 1, 1, 1, MATRIX_T, MATRIX_T> (STMulvecnoise, ST_temp, Val);
            myval = one/Val[0][0];
            mag = (myval.real())*(myval.real()) + (myval.imag())*(myval.imag());
            Spectrum[0][i].imag(0);
            Spetcrum[0][i].real(mag); 
                       
        };
        
        void music(const MATRIX_T A[A_ROWS][A_COLS], const MATRIX_T Steering[C_ROWS][N_Steer], MATRIX_R Angles[N_Signal]){
            MATRIX_T a_i[A_ROWS][A_COLS];
            MATRIX_T c_i[C_ROWS][C_COLS];
            MATRIX_T S_vec[C_ROWS][C_COLS];
            MATRIX_T MISpectrum[1][N_Steer];
            MATRIX_T ST[C_ROWS][N_Steer];
            MATRIX_R Angles[N_Signal];

            a_row_loop : for(int r = 0; r < A_ROWS; r++){
                a_col_loop : for(int c = 0; c < A_COLS; c++){
                    a_i[r][c] = A[r][c];
                }
            }

            b_row_loop : for(int r = 0; r < C_ROWS; r++){
                b_col_loop : for(int c = 0; c < N_Steer; c++){
                    ST[r][c] = Steering[r][c];
                }
            }
            correlation_egv(a_i, c_i, S_vec);
            Spectrum(S_vec, ST, MISpectrum);
            //TODO peak
        }
};
int main(){
	Mus obj;
	obj.hello();
}
