#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#pragma once



class complex
{
private:
    int form;
    double re, im,r,a; 
public:
    friend CString output(complex );
    friend complex sop(complex );
    friend complex pow(complex obj1, complex obj2);
    friend void sqrt(complex obj, complex& obj1, complex& obj2);
    complex& operator = (complex);
    complex operator + (complex);
    complex operator - (complex);
    complex operator * (complex&);
    complex operator / (complex&);

    complex()
    {
        form = 0;
        re = 1;
        im = 0;
        r = abs();
        a = arg();

    }
    complex(const complex& obj)
    {
        this->form = obj.form;
        this->re = obj.re;
        this->im = obj.im;
        this->r = obj.r;
        this->a = obj.a;
    }

    ~complex() {}

    double get_re()
    {
        return re;
    }

    double get_im()
    {
        return im;
    }

    double get_r()
    {
        return r;
    }

    double get_a()
    {
        return a;
    }

    int get_form()
    {
        return form;
    }

    void set_re(double value)
    {
        re = value;
    }

    void set_im(double value)
    {
        im = value;;
    }

    void set_form(int value)
    {
        form = value;
    }

    

    void Set(CString& input)
    {
            bool inputerror = FALSE;
            CString temp, t;
            input.MakeLower();
            if ((input.FindOneOf(_T("()cosn"))) != -1)
            {
                this->form = 1;
                for (int i = 0; i < input.GetLength(); i++)
                {

                    t = input.GetAt(i);
                    if (t.FindOneOf(_T("+-1234567890cosin. ()")) != 0)
                    {
                        inputerror = TRUE;
                        input.SetAt(i, ' ');
                    }
                }
                input.Remove(' ');

                temp = input;
                for (int i = 0; i < temp.GetLength(); i++)
                {
                    t = temp.GetAt(i);
                    if (t.FindOneOf(_T("+cosin()")) != 0)
                    {
                        temp.SetAt(i, ' ');
                    }
                }
                temp.Remove(' ');
                if (input.GetLength() == temp.GetLength())inputerror = TRUE;
                if (temp != _T("(cos()+isin())"))inputerror = TRUE;
                if (inputerror)
                {
                    AfxMessageBox(_T("Ошибка ввода"));
                }
            }

            if ((input.FindOneOf(_T("e^"))) != -1)
            {
                this->form = 2;
                for (int i = 0; i < input.GetLength(); i++)
                {

                    temp = input.GetAt(i);
                    if ((temp.FindOneOf(_T("+-1234567890.e^i ")) != 0))
                    {
                        inputerror = TRUE;
                        input.SetAt(i, ' ');
                    }

                }

                input.Remove(' ');

                temp = input;
                for (int i = 0; i < temp.GetLength(); i++)
                {
                    t = temp.GetAt(i);
                    if (t.FindOneOf(_T("e^i")) != 0)
                    {
                        temp.SetAt(i, ' ');
                    }
                }
                temp.Remove(' ');
                if (input.GetLength() == temp.GetLength())inputerror = TRUE;
                if (temp != _T("e^i"))inputerror = TRUE;
                if (inputerror)
                {
                    AfxMessageBox(_T("Ошибка ввода"));
                }

            }

            if ((this->form != 1) && (this->form != 2))
            {
                this->form = 0;
                for (int i = 0; i < input.GetLength(); i++)
                {

                    temp = input.GetAt(i);
                    if ((temp.FindOneOf(_T("+-1234567890.i ")) != 0))
                    {
                        inputerror = TRUE;
                        input.SetAt(i, ' ');
                    }
                }
                input.Remove(' ');
                if (inputerror)
                {
                    AfxMessageBox(_T("Ошибка ввода"));
                }
            }

        switch (this->form)
        {
        case 0://re+imi
        {
            int rl = 0, pi = 0;
            for (int i = 0; i < input.GetLength(); i++)
            {
                if (((input.GetAt(i) == '-') || (input.GetAt(i) == '+')) && (i != 0))
                {
                    rl = i;
                    break;
                }
                if (input.GetAt(i) == 'i')
                {
                    pi = i;
                    break;
                }
            }
            if (rl != 0) {
                this->re = _wtof(input.Left(rl));
                this->im = _wtof(input.Mid((rl), (input.GetLength() - rl - 1)));
                this->r = this->abs();
                this->a = this->arg();

            }else 
                if (pi != 0)
                {
                    this->re = 0;
                    this->im = _wtof(input.Left(pi));
                    this->r = this->abs();
                    this->a = this->arg();
                }
                else
                {
                    this->re = _wtof(input);
                    this->im = 0;
                    this->r = this->abs();
                    this->a = this->arg();
                }
            
        }break;
        case 1://r(cos(a)+isin(a))
        {
            int c = input.FindOneOf(_T("(")), zc = input.FindOneOf(_T(")"));
            double second_a;

            this->r = _wtof(input.Left(c));
            this->a = _wtof(input.Mid((c + 5), (zc - c - 4)));
            this->set_re(r* cos(a));
            this->set_im(r* sin(a));
            second_a = _wtof(input.Mid((c + 11 + (zc - c - 4)), (zc - c - 3)));
            if (a != second_a) AfxMessageBox(_T("Углы не равны"));
        }break;
        case 2://re^ai
        {
            int e = 0;
            for (int i = 0; i < input.GetLength(); i++)
            {
                if ((input.GetAt(i) == 'e'))
                {
                    e = i;
                    break;
                }
            }
            this->r = _wtof(input.Left(e));
            this->a = _wtof(input.Mid((e + 2), (input.GetLength() - e - 2)));
            this->re=(r * cos(a));
            this->im=(r * sin(a));
        }break;
        case -1:
        {
            this->re = 0;
            this->im = 0;
        }break;
        }
    
    }

    double abs()
    {
        double abs;
        abs = sqrt(this->re * this->re + this->im * this->im);
        return abs;
    }

    double arg()
    {
        double ar=1, x = this->re, y = this->im;
            if (x > 0)ar = atan(y / x);
            if ((x < 0) && (y >= 0))ar = atan(y / x) + M_PI;
            if ((x < 0) && (y < 0))ar = atan(std::abs(y / x)) - M_PI;
            if ((x == 0) && (y > 0))ar = M_PI_2;
            if ((x == 0) && (y < 0))ar = -M_PI_2;
            if ((x == 0) && (y < 0))ar = NAN;
        return ar;
    }
    

};

CString output(complex obj)
{
    CString  sre, sim, str;
    double re = obj.get_re(), im = obj.get_im(), r = obj.get_r(), a = obj.get_a();
    if (obj.get_form() == 0)
    {
        sre.Format(_T("%.2f\n"), re);
        sim.Format(_T("%.2f\n"), im);
        if ((im == 0) || (im > 0))str = sre + _T("+") + sim + _T("i"); else str = sre + sim + _T("i");
    }
    else {
        sre.Format(_T("%.2f\n"), r);
        sim.Format(_T("%.2f\n"), a);
        if (obj.get_form() == 1) str = sre + _T("(cos(") + sim + _T(")+isin(") + sim + _T("))");
        else     str = sre + _T("e^(") + sim + _T("i)");
    }
    
    return str;
}



complex sop(complex obj)
{
    obj.set_re(obj.re);
    obj.set_im( -1 * obj.im);
    obj.r = obj.abs();
    obj.a = obj.arg();
    return obj;
}



complex  pow(complex obj, complex obj2)
{
    complex pow = obj;
    int n = int(obj2.get_re());
    for (n; n > 1; n--) pow = pow * obj;
    pow.r = pow.abs();
    pow.a = pow.arg();
    return  pow;
}

void sqrt(complex obj, complex& obj1, complex& obj2)
{
    obj1.re = sqrt(obj.abs()) * cos(obj.arg() / 2.0);
    obj1.im = sqrt(obj.abs()) * sin(obj.arg() / 2.0);
    obj2.re = obj1.re + M_PI_2;
    obj2.im = obj1.im + M_PI_2;
}



complex complex::operator*(complex& obj)
{
    double temp_re, temp_im;
    temp_re = re * obj.re - im * obj.im;
    temp_im = re * obj.im + obj.re * im;
    obj.re = temp_re;
    obj.im = temp_im;
    obj.r = obj.abs();
    obj.a = obj.arg();
    obj.set_form(obj.get_form());
    return  obj;
}

complex complex::operator/(complex& obj)
{
    double temp_re, temp_im,k;
    k = (obj.re * obj.re + obj.im * obj.im);
   temp_re = (obj.re * re + obj.im * im) / k;
   temp_im = (re * obj.im - obj.re * im) / k;
   obj.re = temp_re;
   obj.im = temp_im;
   obj.r = obj.abs();
   obj.a = obj.arg();
   obj.set_form(obj.get_form());
   return  obj;
}

complex& complex::operator =(complex obj)
{
    form = obj.form;
    re = obj.re;
    im = obj.im;
    r = obj.r;
    a = obj.a;
    return *this;
}

complex complex::operator+(complex obj)
{

    obj.re = this->re + obj.re;
    obj.im = this->im + obj.im;
    obj.r = obj.abs();
    obj.a = obj.arg();
    obj.set_form(obj.get_form());
    return obj;
}

complex complex::operator-(complex obj)
{
    obj.re = this->re - obj.re;
    obj.im = this->im - obj.im;
    obj.r = obj.abs();
    obj.a = obj.arg();
    obj.set_form(obj.get_form());
    return obj;
}


