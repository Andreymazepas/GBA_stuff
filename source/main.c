#include "toolbox.h"

int main()
{
    int ii, jj;

	REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	m3_fill(RGB15(12, 12, 14));
	for(ii=0; ii<=14; ii++)
	{
		jj= 2*ii+7;
        m3_line(0, 11*ii, 17*ii, 160, RGB15(jj, 0, jj));
        //m3_line(0, 160-11*ii, 17*ii, 0, RGB15(jj, 0, jj));
        m3_line(17*ii, 0, 240, 11*ii, RGB15(jj, 0, jj));
        //m3_line(240-17*ii, 160, 240, 11*ii, RGB15(jj, 0, jj));

	}

    while(1);

    return 0;
}