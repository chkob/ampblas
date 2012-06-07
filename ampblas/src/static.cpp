/*----------------------------------------------------------------------------
 * Copyright � Microsoft Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not 
 * use this file except in compliance with the License.  You may obtain a copy 
 * of the License at http://www.apache.org/licenses/LICENSE-2.0  
 * 
 * THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED 
 * WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE, 
 * MERCHANTABLITY OR NON-INFRINGEMENT. 
 *
 * See the Apache Version 2.0 License for specific language governing 
 * permissions and limitations under the License.
 *---------------------------------------------------------------------------
 * 
 * ampblas_static.h
 *
 * Instantiates the implementations to be included in the static library
 *
 *---------------------------------------------------------------------------*/

#include "ampblas.h"
#include "ampblas_complex.h"

#include "ampblas_static.h"

namespace ampblas_static {

//-----------------------------------------------------------------------------
// BLAS 3
//-----------------------------------------------------------------------------

void gemm(const concurrency::accelerator_view& av, enum class transpose transa, enum class transpose transb, float alpha, const concurrency::array_view<const float,2>& a, const concurrency::array_view<const float,2>& b, float beta, const concurrency::array_view<float,2>& c)
{
    ampblas::gemm(av, transa, transb, alpha, a, b, beta, c);
}

void gemm(const concurrency::accelerator_view& av, enum class transpose transa, enum class transpose transb, double alpha, const concurrency::array_view<const double,2>& a, const concurrency::array_view<const double,2>& b, double beta, const concurrency::array_view<double,2>& c)
{
    ampblas::gemm(av, transa, transb, alpha, a, b, beta, c);
}

void gemm(const concurrency::accelerator_view& av, enum class transpose transa, enum class transpose transb, complex<float> alpha, const concurrency::array_view<const complex<float>,2>& a, const concurrency::array_view<const complex<float>,2>& b, complex<float> beta, const concurrency::array_view<complex<float>,2>& c)
{
    ampblas::gemm(av, transa, transb, alpha, a, b, beta, c);
}

void gemm(const concurrency::accelerator_view& av, enum class transpose transa, enum class transpose transb, complex<double> alpha, const concurrency::array_view<const complex<double>,2>& a, const concurrency::array_view<const complex<double>,2>& b, complex<double> beta, const concurrency::array_view<complex<double>,2>& c)
{
    ampblas::gemm(av, transa, transb, alpha, a, b, beta, c);
}

} // namespace ampblas_static
