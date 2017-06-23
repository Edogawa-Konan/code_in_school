//
// @author prime on 2017/6/18.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int NC,NP;
    scanf("%d",&NC);
    vector<int> coupon(NC);
    for (int i=0;i<NC;++i)
    {
        scanf("%d",&coupon[i]);
    }
    scanf("%d",&NP);
    vector<int> product(NP);
    for (int i=0;i<NP;++i)
        scanf("%d",&product[i]);
    sort(coupon.begin(),coupon.end());//升序
    sort(product.begin(),product.end());
    long res=0;
    for(auto c_it=coupon.rbegin(),p_it=product.rbegin();c_it!=coupon.rend()&&p_it!=product.rend()&&*c_it>0&&*p_it>0;c_it++,p_it++)
    {
        res+=(*c_it)*(*p_it);
    }
    for(auto c_it=coupon.begin(),p_it=product.begin();c_it!=coupon.end()&&p_it!=product.end()&&*c_it<0&&*p_it<0;c_it++,p_it++)
    {
        res+=(*c_it)*(*p_it);
    }
    printf("%ld",res);
    return 0;
}

