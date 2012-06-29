#include "tune.h"
#include "template.h"

TUNE_NAMESPACE_BEGIN

template <>
void do_test<dcomplex, transpose::trans, transpose::no_trans>(concurrency::accelerator_view& av, dcomplex alpha, const concurrency::array_view<const dcomplex,2>& a, const concurrency::array_view<const dcomplex,2>& b, dcomplex beta, const concurrency::array_view<dcomplex,2>&c, const std::vector<dcomplex>& c_ref, int offset)
{
    #include "../../data/zgemm_tn.data"
}

TUNE_NAMESPACE_END
