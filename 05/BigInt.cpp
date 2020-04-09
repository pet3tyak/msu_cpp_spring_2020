#include "BInt.h"
#define MAX_CELL 1000000000
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
    if (int x=val/MAX_CELL)
    {
        this->size++;
        this->head=(int*)malloc(2*sizeof(int));
        this->head[1]=x;
        this->head[0]=val%MAX_CELL;
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
    this->size=1;
    this->sign=(val>=0);
    if (!this->sign)
        val*=-1;
    if (int x=val/MAX_CELL)
    {
        this->size++;
        this->ChangeMem(this->size,true);
        this->head[1]=x;
        this->head[0]=val%MAX_CELL;
    }
    else
    {
        this->ChangeMem(this->size,true);
        this->head[0]=val;
    }
    return *this;
}

BigInt& BigInt::operator=(const BigInt& val)
{
    this->size=val.size;
    this->sign=val.sign;
    this->ChangeMem(this->size,true);
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
        int m=MAX_CELL/10;
        for (j=0;j<9;j++)
        {
            cc<<k[val.size-i-1]/m%10;
            m/=10;
        }
    }
    return cc;
}

BigInt BigInt::operator-() const
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

BigInt BigInt::abs() const
{
    BigInt l=*this;
    l.sign=true;
    return l;
}

BigInt BigInt::operator+(const BigInt &b) const
{
    if (b.size>this->size)
        return b+*this;
    BigInt c=*this;
    if (c.sign==b.sign)
    {
        for (int i=0;i<c.size;i++)
        {
            c.head[i]+=b.head[i];
            if (c.head[i]/MAX_CELL)
            {
                if (i==c.size-1)
                {
                    c.size+=1;
                    c.ChangeMem(c.size,false);
                    c.head[c.size-1]=0;
                }
                c.head[i+1]+=c.head[i]%MAX_CELL;
                c.head[i]=c.head[i]/MAX_CELL;
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
                    c.head[i]+=MAX_CELL;
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
                    l.head[i]+=MAX_CELL;
                }
            }
            c=l;
        }
        return c;
    }
    return c;
}

BigInt BigInt::operator-(const BigInt &b) const
{
    return *this+(-b);
}

BigInt BigInt::operator+(const int b) const
{
    return *this+BigInt(b);
}

BigInt BigInt::operator-(const int b) const
{
    return *this-BigInt(b);
}

bool BigInt::ChangeMem(int size,bool isfree)
{
    this->size=size;
    if (isfree)
    {
        if (this->head)
            free(this->head);
        this->head=(int*)malloc(this->size*sizeof(int));
    }
    else
    {
        this->head=(int*)realloc(this->head,this->size*sizeof(int));
    }
    if (!this->head)
    {
        throw std::bad_alloc();
        return false;
    }
    return true;
}
