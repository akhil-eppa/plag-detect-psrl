
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

int add(int ,int );
int sub(int ,int );
int main();

static char *lance_static_t9 = "%d %d\n";

int add(int a_2,int b_3)
{
 int c_8;
 int t5;


 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ while(p < 1) {$ */

 LL1:

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ c = a + b ;$ */

	t5 = a_2 + b_3;
	c_8 = t5;

 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ return c ;$ */

	return c_8;

}

int sub(int a_9,int b_10)
{
 int c_13;
 int t6;


 /* 19 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ c = a - b ;$ */

	t6 = a_9 - b_10;
	c_13 = t6;

 /* 20 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ return c ;$ */

	return c_13;

}

int main()
{
 int a_15;
 int b_16;
 int t7;
 int c_17;
 int t8;
 int d_18;
 int t10;


 /* 24 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ int a = 10;$ */

	a_15 = 10;

 /* 25 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ int b = 15;$ */

	b_16 = 15;

 /* 26 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ int c = add(a,b);$ */

	t7 = add(a_15,b_16);
	c_17 = t7;

 /* 27 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ int d = sub(a,b);$ */

	t8 = sub(a_15,b_16);
	d_18 = t8;

 /* 28 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_3.c" */
 /* $ printf("%d %d\n",c,d);$ */

	t10 = printf(lance_static_t9,c_17,d_18);

 /* 0 "???" */
 /* $ ???$ */

	return;

}