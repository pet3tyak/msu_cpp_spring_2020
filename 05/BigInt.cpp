#include "BInt.h"

BigInt::BigInt()
{
    size=1;
    this->head=(int*)malloc(sizeof(int));
    sign=true;
}

BigInt::BigInt(int val)
{
    this->size=1;
    this->sign=(val>=0);
    if (!this->sign)
        val*=-1;
    if (int x=val/1000000000)
    {
        this->size++;
        this->head=(int*)malloc(2*sizeof(int));
        this->head[1]=x;
        this->head[0]=val%1000000000;
    }
    else
    {
        this->head=(int*)malloc(sizeof(int));
        this->head[0]=val;
    }
}

BigInt::BigInt(const BigInt& val)
{
    this->size=val.size;
    this->sign=val.sign;
    this->head=(int*)malloc(this->size*sizeof(int));
    if (!this->head)
    {
        std::cout<<"Cannot allocate memory"<<std::endl;
        return;
    }
    for (int i=0; i<this->size;i++)
    {
        this->head[i]=val.head[i];
    }
}

BigInt::~BigInt()
{
    if (this->head)
        free(this->head);
}

BigInt& BigInt::operator=(int val)
{
    free(this->head);
    this->size=1;
    this->sign=(val>=0);
    if (!this->sign)
        val*=-1;
    if (int x=val/1000000000)
    {
        this->size++;
        this->head=(int*)malloc(2*sizeof(int));
        if (!this->head)
        {
            std::cout<<"Cannot allocate memory"<<std::endl;
            return *this;
        }
        this->head[1]=x;
        this->head[0]=val%1000000000;
    }
    else
    {
        this->head=(int*)malloc(sizeof(int));
        if (!this->head)
        {
            std::cout<<"Cannot allocate memory"<<std::endl;
            return *this;
        }
        this->head[0]=val;
    }
    return *this;
}

BigInt& BigInt::operator=(const BigInt& val)
{
    if (this->head)
        free(this->head);
    this->size=val.size;
    this->sign=val.sign;
    this->head=(int*)malloc(this->size*sizeof(int));
    if (!this->head)
        {
            std::cout<<"Cannot allocate memory"<<std::endl;
            return *this;
        }
    for (int i=0; i<this->size;i++)
    {
        this->head[i]=val.head[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream &cc, const BigInt& val)
{
    int j=0,r=1,i;
    int k[val.size];
    bool c=false;
    for (i=0;i<val.size;i++)
    {
        k[i]=val.head[i];
        if (k[i])
            c=true;
    }
    if(!c)
    {
        cc<<0;
        return cc;
    }
    if (!val.sign)
        cc<<'-';
    for (i=0;i<val.size;i++)
    {
        if (k[val.size-i-1])
        {
            break;
        }
    }
    cc<<k[val.size-i-1];
    i++;
    for (;i<val.size;i++)
    {
        int m=100000000;
        for (j=0;j<9;j++)
        {
            cc<<k[val.size-i-1]/m%10;
            m/=10;
        }
    }
    return cc;
}

const BigInt BigInt::operator-() const
{
    BigInt c=*this;
    if (c.sign)
    {
        c.sign=false;
    }
    else
    {
        c.sign=true;
    }
    return c;
}

bool BigInt::operator==(const BigInt& val) const
{
    if (this->sign!=val.sign)
        return false;
    for (int i=this->size>=val.size?this->size:val.size;i>0;i--)
    {
        if(i>this->size?0:this->head[i]!=i>val.size?0:val.head[i])
            return false;
    }
    return true;
}
bool BigInt::operator==(const int val) const
{
    return *this==BigInt(val);
}
bool BigInt::operator>(const BigInt& val) const
{
    if (this->sign!=val.sign)
    {
        if (val.sign)
        {
            return false;
        }
        return true;
    }
    for (int i=(this->size>=val.size)?this->size:val.size;i>0;i--)
    {
        if(((i>this->size)?0:this->head[i])<((i>val.size)?0:val.head[i]))
            return !this->sign;
    }
    return this->sign;
}

bool BigInt::operator>(const int val) const
{
    return *this>BigInt(val);
}

bool BigInt::operator<(const BigInt& val) const
{
    if (this->sign!=val.sign)
    {
        if (!val.sign)
        {
            return false;
        }
        return true;
    }
    for (int i=(this->size>=val.size)?this->size:val.size;i>0;i--)
    {
        if(((i>this->size)?0:this->head[i])>((i>val.size)?0:val.head[i]))
            return !this->sign;
    }
    return this->sign;
}

bool BigInt::operator<(const int val) const
{
    return *this<BigInt(val);
}

bool BigInt::operator<=(const BigInt& val) const
{
    return !(*this>val);
}

bool BigInt::operator<=(const int val) const
{
    return *this<=BigInt(val);
}

bool BigInt::operator>=(const BigInt& val) const
{
    return !(*this<val);
}

bool BigInt::operator>=(const int val) const
{
    return *this>=BigInt(val);
}

const BigInt BigInt::abs() const
{
    BigInt l=*this;
    l.sign=true;
    return l;
}

const BigInt BigInt::operator+(const BigInt &b) const
{
    if (b.size>this->size)
        return b+*this;
    BigInt c=*this;
    if (c.sign==b.sign)
    {
        for (int i=0;i<c.size;i++)
        {
            c.head[i]+=b.head[i];
            if (c.head[i]/1000000000)
            {
                if (i==c.size-1)
                {
                    c.size+=1;
                    c.head=(int*)realloc(c.head,c.size*sizeof(int));
                    if (!c.head)
                        {
                            std::cout<<"Cannot allocate memory"<<std::endl;
                            return *this;
                        }
                    c.head[c.size-1]=0;
                }
                c.head[i+1]+=c.head[i]%1000000000;
                c.head[i]=c.head[i]/1000000000;
            }
        }
    }
    else
    {
        if (c.abs()>b.abs())
        {
            for (int i=0;i<(c.size>b.size?b.size:c.size);i++)
            {
                c.head[i]-=b.head[i];
                if (c.head[i]<0)
                {
                    c.head[i+1]--;
                    c.head[i]+=1000000000;
                }
            }
        }
        else
        {
            BigInt l=b;
            for (int i=0;i<(l.size>c.size?c.size:l.size);i++)
            {
                l.head[i]-=c.head[i];
                if (l.head[i]<0)
                {
                    l.head[i+1]--;
                    l.head[i]+=1000000000;
                }
            }
            c=l;
        }
        return c;
    }
    return c;
}

const BigInt BigInt::operator-(const BigInt &b) const
{
    return *this+(-b);
}

const BigInt BigInt::operator+(const int b) const
{
    return *this+BigInt(b);
}

const BigInt BigInt::operator-(const int b) const
{
    return *this-BigInt(b);
}
