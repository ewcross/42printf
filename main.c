/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:05:07 by ecross            #+#    #+#             */
/*   Updated: 2019/11/27 13:10:44 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <locale.h>

/*types: c s p di u x X f e n*/
/*
test ' flag with:
			- #
			- precision alone
			- precision with 0 flag
*/


int main(int argc, char **v)
{
	(void)argc;

	setlocale(LC_NUMERIC, "en_GB");

//Floats - Basic
int f_basic_1(void){return test("this %f float", 1.5);}
int f_basic_fltonly(void){return test("%f", 7.5);}
int f_basic_whole(void){return test("%f", 1.0);}
int f_basic_negative(void){return test("%f", -3.85);}
int f_basic_positive_3_3(void){return test("%f", 573.924);}
int f_basic_negative_3_3(void){return test("%f", -958.125);}
int f_basic_positive_smallfpart(void){return test("%f", 23.00041);}
int f_basic_positive_allsmall(void){return test("%f", 0.000039);}
int f_basic_negative_smallfpart(void){return test("%f", -7.00036);}
int f_basic_negative_allsmall(void){return test("%f", -0.00032);}
int f_basic_limits_allsmall_pos(void){return test("%f", 0.000001);}
int f_basic_limits_allsmall_neg(void){return test("%f", -0.000001);}
int f_basic_limits_smallfpart_pos(void){return test("%f", 9873.000001);}
int f_basic_limits_smallfpart_neg(void){return test("%f", -875.000001);}
int f_basic_limits_allbig_pos(void){return test("%f", 999.999999);}
int f_basic_limits_allbig_neg(void){return test("%f", -99.999999);}
int f_basic_limits_bigfpart_pos(void){return test("%f", 0.999999);}
int f_basic_limits_bigfpart_neg(void){return test("%f", -0.999999);}
//Floats - Rounding with default precision
int f_rndd_pos(void){return test("%f", 23.375094499);}
int f_rndd_neg(void){return test("%f", -985.765426499);}
int f_rndu_pos(void){return test("%f", 0.0894255);}
int f_rndu_neg(void){return test("%f", -56.2012685);}
int f_rndu_multidigit_pos(void){return test("%f", 43.4399999);}
int f_rndu_multidigit_neg(void){return test("%f", -5.0299999);}
int f_rndd_multidigit_pos(void){return test("%f", 43.43999949);}
int f_rndd_multidigit_neg(void){return test("%f", -5.02999949);}
int f_rndd_wholnobump_pos(void){return test("%f", 1.99999949);}
int f_rndd_wholnobump_neg(void){return test("%f", -0.99999949);}
int f_rndu_bumpwhole_pos(void){return test("%f", 3.9999999);}
int f_rndu_bumpwhole_neg(void){return test("%f", -5.9999999);}
//Floats Prec 0
int f_prec0_1(void){return test("this %.0f float", 1.6);}
int f_prec0_fltonly(void){return test("%.0f", 7.4);}
int f_prec0_whole(void){return test("%.0f", 1.0);}
int f_prec0_negative(void){return test("%.0f", -3.85);}
int f_prec0_positive_3_3(void){return test("%.0f", 573.924);}
int f_prec0_negative_3_3(void){return test("%.0f", -958.125);}
int f_prec0_positive_smallfpart(void){return test("%.0f", 23.00041);}
int f_prec0_positive_allsmall(void){return test("%.0f", 0.000039);}
int f_prec0_negative_smallfpart(void){return test("%.0f", -7.00036);}
int f_prec0_negative_allsmall(void){return test("%.0f", -0.00032);}
//Floats Prec 1
int f_prec1_1(void){return test("this %.1f float", 1.5);}
int f_prec1_fltonly(void){return test("%.1f", 7.5);}
int f_prec1_whole(void){return test("%.1f", 1.0);}
int f_prec1_negative(void){return test("%.1f", -3.85);}
int f_prec1_positive_3_3(void){return test("%.1f", 573.924);}
int f_prec1_negative_3_3(void){return test("%.1f", -958.125);}
int f_prec1_positive_smallfpart(void){return test("%.1f", 23.00041);}
int f_prec1_positive_allsmall(void){return test("%.1f", 0.000039);}
int f_prec1_negative_smallfpart(void){return test("%.1f", -7.00036);}
int f_prec1_negative_allsmall(void){return test("%.1f", -0.00032);}
//Floats Prec 3
int f_prec3_1(void){return test("this %.3f float", 1.5);}
int f_prec3_fltonly(void){return test("%.3f", 7.5);}
int f_prec3_whole(void){return test("%.3f", 1.0);}
int f_prec3_negative(void){return test("%.3f", -3.85);}
int f_prec3_positive_3_3(void){return test("%.3f", 573.924);}
int f_prec3_negative_3_3(void){return test("%.3f", -958.125);}
int f_prec3_positive_smallfpart(void){return test("%.3f", 23.00041);}
int f_prec3_positive_allsmall(void){return test("%.3f", 0.000039);}
int f_prec3_negative_smallfpart(void){return test("%.3f", -7.00036);}
int f_prec3_negative_allsmall(void){return test("%.3f", -0.00032);}
//Floats - Prec 7
int f_prec7_1(void){return test("this %.7f float", 1.5);}
int f_prec7_fltonly(void){return test("%.7f", 7.5);}
int f_prec7_whole(void){return test("%.7f", 1.0);}
int f_prec7_negative(void){return test("%.7f", -3.85);}
int f_prec7_positive_3_3(void){return test("%.7f", 573.924);}
int f_prec7_negative_3_3(void){return test("%.7f", -958.125);}
int f_prec7_positive_smallfpart(void){return test("%.7f", 23.00041);}
int f_prec7_positive_allsmall(void){return test("%.7f", 0.0000039);}
int f_prec7_negative_smallfpart(void){return test("%.7f", -7.00036);}
int f_prec7_negative_allsmall(void){return test("%.7f", -0.000032);}
int f_prec7_limits_allsmall_pos(void){return test("%.7f", 0.0000001);}
int f_prec7_limits_allsmall_neg(void){return test("%.7f", -0.0000001);}
int f_prec7_limits_smallfpart_pos(void){return test("%.7f", 9873.000001);}
int f_prec7_limits_smallfpart_neg(void){return test("%.7f", -875.000001);}
int f_prec7_limits_allbig_pos(void){return test("%.7f", 999.9999999);}
int f_prec7_limits_allbig_neg(void){return test("%.7f", -99.9999999);}
int f_prec7_limits_bigfpart_pos(void){return test("%.7f", 0.999999);}
int f_prec7_limits_bigfpart_neg(void){return test("%.7f", -0.999999);}
//Floats - Prec 7 Rounding
int f_rnd_prec7_rndd_pos(void){return test("%.7f", 23.375094499);}
int f_rnd_prec7_rndd_neg(void){return test("%.7f", -985.765426499);}
int f_rnd_prec7_rndu_pos(void){return test("%.7f", 0.0894255);}
int f_rnd_prec7_rndu_neg(void){return test("%.7f", -56.2012685);}
int f_rnd_prec7_rndu_multidigit_pos(void){return test("%.7f", 43.4399999);}
int f_rnd_prec7_rndu_multidigit_neg(void){return test("%.7f", -5.0299999);}
int f_rnd_prec7_rndd_multidigit_pos(void){return test("%.7f", 43.43999949);}
int f_rnd_prec7_rndd_multidigit_neg(void){return test("%.7f", -5.02999949);}
int f_rnd_prec7_rndd_wholnobump_pos(void){return test("%.7f", 1.99999949);}
int f_rnd_prec7_rndd_wholnobump_neg(void){return test("%.7f", -0.99999949);}
int f_rnd_prec7_rndu_bumpwhole_pos(void){return test("%.7f", 3.9999999);}
//Floats - Prec 8
int f_prec8_1(void){return test("this %.8f float", 1.5);}
int f_prec8_fltonly(void){return test("%.8f", 7.5);}
int f_prec8_whole(void){return test("%.8f", 1.0);}
int f_prec8_negative(void){return test("%.8f", -3.85);}
int f_prec8_positive_3_3(void){return test("%.8f", 573.924);}
int f_prec8_negative_3_3(void){return test("%.8f", -958.125);}
int f_prec8_positive_smallfpart(void){return test("%.8f", 23.00041);}
int f_prec8_positive_allsmall(void){return test("%.8f", 0.00000039);}
int f_prec8_negative_smallfpart(void){return test("%.8f", -7.00036);}
int f_prec8_negative_allsmall(void){return test("%.8f", -0.0000032);}
int f_prec8_limits_allsmall_pos(void){return test("%.8f", 0.00000001);}
int f_prec8_limits_allsmall_neg(void){return test("%.8f", -0.00000001);}
int f_prec8_limits_smallfpart_pos(void){return test("%.8f", 9873.000001);}
int f_prec8_limits_smallfpart_neg(void){return test("%.8f", -875.000001);}
int f_prec8_limits_allbig_pos(void){return test("%.8f", 999.9999999);}
int f_prec8_limits_allbig_neg(void){return test("%.8f", -99.99999999);}
int f_prec8_limits_bigfpart_pos(void){return test("%.8f", 0.999999);}
int f_prec8_limits_bigfpart_neg(void){return test("%.8f", -0.999999);}
//Floats - Prec 8 Rounding
int f_rnd_prec8_rndd_pos(void){return test("%.8f", 23.375094499);}
int f_rnd_prec8_rndd_neg(void){return test("%.8f", -985.765426499);}
int f_rnd_prec8_rndu_pos(void){return test("%.8f", 0.0894255);}
int f_rnd_prec8_rndu_neg(void){return test("%.8f", -56.2012685);}
int f_rnd_prec8_rndu_multidigit_pos(void){return test("%.8f", 43.4399999);}
int f_rnd_prec8_rndu_multidigit_neg(void){return test("%.8f", -5.0299999);}
int f_rnd_prec8_rndd_multidigit_pos(void){return test("%.8f", 43.43999949);}
int f_rnd_prec8_rndd_multidigit_neg(void){return test("%.8f", -5.02999949);}
int f_rnd_prec8_rndd_wholnobump_pos(void){return test("%.8f", 1.99999949);}
int f_rnd_prec8_rndd_wholnobump_neg(void){return test("%.8f", -0.99999949);}
int f_rnd_prec8_rndu_bumpwhole_pos(void){return test("%.8f", 3.9999999);}
//Floats - Prec 9
int f_stress_prec9_1(void){return test("this %.9f float", 1.5);}
int f_stress_prec9_fltonly(void){return test("%.9f", 7.5);}
int f_stress_prec9_whole(void){return test("%.9f", 1.0);}
int f_stress_prec9_negative(void){return test("%.9f", -3.85);}
int f_stress_prec9_positive_3_3(void){return test("%.9f", 573.924);}
int f_stress_prec9_negative_3_3(void){return test("%.9f", -958.125);}
int f_stress_prec9_positive_smallfpart(void){return test("%.9f", 23.00041);}
int f_stress_prec9_positive_allsmall(void){return test("%.9f", 0.00000039);}
int f_stress_prec9_negative_smallfpart(void){return test("%.9f", -7.00036);}
int f_stress_prec9_negative_allsmall(void){return test("%.9f", -0.0000032);}
int f_stress_prec9_limits_allsmall_pos(void){return test("%.9f", 0.00000001);}
int f_stress_prec9_limits_allsmall_neg(void){return test("%.9f", -0.00000001);}
int f_stress_prec9_limits_smallfpart_pos(void){return test("%.9f", 9873.000001);}
int f_stress_prec9_limits_smallfpart_neg(void){return test("%.9f", -875.000001);}
int f_stress_prec9_limits_allbig_pos(void){return test("%.9f", 999.99999999);}
int f_stress_prec9_limits_allbig_neg(void){return test("%.9f", -99.99999999);}
int f_stress_prec9_limits_bigfpart_pos(void){return test("%.9f", 0.999999);}
int f_stress_prec9_limits_bigfpart_neg(void){return test("%.9f", -0.999999);}
//Floats - Prec 9 Rounding
int f_stress_prec9_rndd_pos(void){return test("%.9f", 23.375094499);}
int f_stress_prec9_rndd_neg(void){return test("%.9f", -985.765426499);}
int f_stress_prec9_rndu_pos(void){return test("%.9f", 0.0894255);}
int f_stress_prec9_rndu_neg(void){return test("%.9f", -56.2012685);}
int f_stress_prec9_rndu_multidigit_pos(void){return test("%.9f", 43.4399999);}
int f_stress_prec9_rndu_multidigit_neg(void){return test("%.9f", -5.0299999);}
int f_stress_prec9_rndd_multidigit_pos(void){return test("%.9f", 43.43999949);}
int f_stress_prec9_rndd_multidigit_neg(void){return test("%.9f", -5.02999949);}
int f_stress_prec9_rndd_wholnobump_pos(void){return test("%.9f", 1.99999949);}
int f_stress_prec9_rndd_wholnobump_neg(void){return test("%.9f", -0.99999949);}
int f_stress_prec9_rndu_bumpwhole_pos(void){return test("%.9f", 3.9999999);}
//Floats - Prec 10
int f_stress_prec10_1(void){return test("this %.10f float", 1.5);}
int f_stress_prec10_fltonly(void){return test("%.10f", 7.5);}
int f_stress_prec10_whole(void){return test("%.10f", 1.0);}
int f_stress_prec10_negative(void){return test("%.10f", -3.85);}
int f_stress_prec10_positive_3_10(void){return test("%.10f", 573.924);}
int f_stress_prec10_negative_3_10(void){return test("%.10f", -958.125);}
int f_stress_prec10_pos(void){return test("%.10f", 23.8341375094);}
int f_stress_prec10_neg(void){return test("%.10f", -985.2459765426);}
int f_stress_prec10_rndd_pos(void){return test("%.10f", 23.8341375094499);}
int f_stress_prec10_rndd_neg(void){return test("%.10f", -985.2459765426499);}
int f_stress_prec10_rndu_pos(void){return test("%.10f", 0.87650894255);}
int f_stress_prec10_rndu_neg(void){return test("%.10f", -56.47852012685);}
int f_stress_prec10_positive_smallfpart(void){return test("%.10f", 23.000000041);}
int f_stress_prec10_positive_allsmall(void){return test("%.10f", 0.0000000039);}
int f_stress_prec10_negative_smallfpart(void){return test("%.10f", -7.000000036);}
int f_stress_prec10_negative_allsmall(void){return test("%.10f", -0.000000032);}
int f_stress_prec10_limits_allsmall_pos(void){return test("%.10f", 0.0000000001);}
int f_stress_prec10_limits_allsmall_neg(void){return test("%.10f", -0.0000000001);}
int f_stress_prec10_limits_smallfpart_pos(void){return test("%.10f", 9873.0000000001);}
int f_stress_prec10_limits_smallfpart_neg(void){return test("%.10f", -875.0000000001);}
int f_stress_prec10_limits_allbig_pos(void){return test("%.10f", 999.9999999999);}
int f_stress_prec10_limits_allbig_neg(void){return test("%.10f", -99.9999999999);}
int f_stress_prec10_limits_bigfpart_pos(void){return test("%.10f", 0.9999999999);}
int f_stress_prec10_limits_bigfpart_neg(void){return test("%.10f", -0.9999999999);}
//Floats - Prec 11
int f_stress_prec11_rndu(void){return test("%.11f",        1.025978541236587568);}
int f_stress_prec11_rndd(void){return test("%.11f",        1.025978548534310421);}
int f_stress_prec11_limits_tiny(void){return test("%.11f", 0.000000000010000000);}
int f_stress_prec11_limits_big(void){return test("%.11f", 99.999999999990000000);}
//Floats - Prec 12
int f_stress_prec12_rndu(void){return test("%.12f",        1.025978541236587568);}
int f_stress_prec12_rndd(void){return test("%.12f",        1.025978548534310421);}
int f_stress_prec12_limits_tiny(void){return test("%.12f", 0.000000000001000000);}
int f_stress_prec12_limits_big(void){return test("%.12f", 99.999999999999000000);}
//Floats - Prec 13
int f_stress_prec13_rndu(void){return test("%.13f",        1.025978541136587568);}
int f_stress_prec13_rndd(void){return test("%.13f",        1.025978548534310421);}
int f_stress_prec13_limits_tiny(void){return test("%.13f", 0.000000000000100000);}
int f_stress_prec13_limits_big(void){return test("%.13f", 99.999999999999900000);}
//Floats - Prec 14
int f_stress_prec14_rndu(void){return test("%.14f",        1.025978541436587568);}
int f_stress_prec14_rndd(void){return test("%.14f",        1.025978548534310421);}
int f_stress_prec14_limits_tiny(void){return test("%.14f", 0.000000000000010000);}
int f_stress_prec14_limits_big(void){return test("%.14f",  9.999999999999990000);}
//Floats - Prec 15
int f_stress_prec15_rndu(void){return test("%.15f",        1.025978542436587568);}
int f_stress_prec15_rndd(void){return test("%.15f",        1.025978548534310421);}
int f_stress_prec15_limits_tiny(void){return test("%.15f", 0.000000000000001000);}
int f_stress_prec15_limits_big(void){return test("%.15f",  0.999999999999999000);}
//Floats - Prec 16
int f_stress_prec16_rndu(void){return test("%.16f",        1.025978542436587568);}
int f_stress_prec16_rndd(void){return test("%.16f",        1.025978548534310421);}
int f_stress_prec16_limits_tiny(void){return test("%.16f", 0.000000000000000100);}
int f_stress_prec16_limits_big(void){return test("%.16f",  0.999999999999999900);}
//Floats - Prec 17
int f_stress_prec17_rndu(void){return test("%.17f",        1.025978542436587568);}
int f_stress_prec17_rndd(void){return test("%.17f",        1.025978548534310421);}
int f_stress_prec17_limits_tiny(void){return test("%.17f", 0.000000000000000010);}
int f_stress_prec17_limits_big(void){return test("%.17f",  0.999999999999999990);}
//Floats - Prec 18
int f_stress_prec18_rndu(void){return test("%.18f",        0.125978542436587568);}
int f_stress_prec18_rndd(void){return test("%.18f",        0.125978548534310421);}
//Floats with altform,~
int		f_af_prec0p(void){return test("%#.0f", 7.4);}
int		f_af_prec1p(void){return test("%#.1f", 7.3);}
int		f_af_prec0n(void){return test("%#.0f", -7.4);}
int		f_af_prec1n(void){return test("%#.1f", -7.3);}
//Floats with allsign,~
int		f_as_prec0p_as(void){return test("%+.0f", 7.4);}
int		f_as_prec3p_as(void){return test("%+.3f", 7.3);}
int		f_as_prec0n_as(void){return test("%+.0f", -7.4);}
int		f_as_prec3n_as(void){return test("%+.3f", -7.3);}
//Floats with field width,~
int f_wprec0p(void){return test("%5.0f", 7.3);}
int f_wprec1p(void){return test("%5.1f", 7.3);}
int f_wprec3p(void){return test("%5.3f", 7.3);}
int f_wprec6p(void){return test("%5.6f", 7.3);}
int f_wprec0n(void){return test("%5.0f", -7.3);}
int f_wprec1n(void){return test("%5.1f", -7.3);}
int f_wprec3n(void){return test("%5.3f", -7.3);}
int f_wprec6n(void){return test("%5.6f", -7.3);}
//Floats with field width and zero padding,~
int f_wzp_prec0p(void){return test("%05.0f", 7.3);}
int f_wzp_prec1p(void){return test("%05.1f", 7.3);}
int f_wzp_prec3p(void){return test("%05.3f", 7.3);}
int f_wzp_prec6p(void){return test("%05.6f", 7.3);}
int f_wzp_prec0n(void){return test("%05.0f", -7.3);}
int f_wzp_prec1n(void){return test("%05.1f", -7.3);}
int f_wzp_prec3n(void){return test("%05.3f", -7.3);}
int f_wzp_prec6n(void){return test("%05.6f", -7.3);}
//Floats with field width and left justify,~
int f_wlj_prec0p(void){return test("%-5.0f", 7.3);}
int f_wlj_prec1p(void){return test("%-5.1f", 7.3);}
int f_wlj_prec3p(void){return test("%-5.3f", 7.3);}
int f_wlj_prec6p(void){return test("%-5.6f", 7.3);}
int f_wlj_prec0n(void){return test("%-5.0f", -7.3);}
int f_wlj_prec1n(void){return test("%-5.1f", -7.3);}
int f_wlj_prec3n(void){return test("%-5.3f", -7.3);}
int f_wlj_prec6n(void){return test("%-5.6f", -7.3);}
//Floats with field width and zero padding and left justify,~
int f_wzplj_prec0p_ignoreflag(void){return test("%-05.0f", 7.3);}
int f_wzplj_prec1p_ignoreflag(void){return test("%-05.1f", 7.3);}
int f_wzplj_prec3p_ignoreflag(void){return test("%-05.3f", 7.3);}
int f_wzplj_prec6p_ignoreflag(void){return test("%-05.6f", 7.3);}
int f_wzplj_prec0n_ignoreflag(void){return test("%-05.0f", -7.3);}
int f_wzplj_prec1n_ignoreflag(void){return test("%-05.1f", -7.3);}
int f_wzplj_prec3n_ignoreflag(void){return test("%-05.3f", -7.3);}
int f_wzplj_prec6n_ignoreflag(void){return test("%-05.6f", -7.3);}
//Floats with field width and zero padding and left justify, rev f order,~
int f_wzpljr_prec0p_ignoreflag(void){return test("%0-5.0f", 7.3);}
int f_wzpljr_prec1p_ignoreflag(void){return test("%0-5.1f", 7.3);}
int f_wzpljr_prec3p_ignoreflag(void){return test("%0-5.3f", 7.3);}
int f_wzpljr_prec6p_ignoreflag(void){return test("%0-5.6f", 7.3);}
int f_wzpljr_prec0n_ignoreflag(void){return test("%0-5.0f", -7.3);}
int f_wzpljr_prec1n_ignoreflag(void){return test("%0-5.1f", -7.3);}
int f_wzpljr_prec3n_ignoreflag(void){return test("%0-5.3f", -7.3);}
int f_wzpljr_prec6n_ignoreflag(void){return test("%0-5.6f", -7.3);}
//Floats with field width and left justify and altform,~
int f_wzpljaf_prec0p(void){return test("%#-5.0f", 7.3);}
int f_wzpljaf_prec1p(void){return test("%#-5.1f", 7.3);}
int f_wzpljaf_prec3p(void){return test("%#-5.3f", 7.3);}
int f_wzpljaf_prec6p(void){return test("%#-5.6f", 7.3);}
int f_wzpljaf_prec0n(void){return test("%#-5.0f", -7.3);}
int f_wzpljaf_prec1n(void){return test("%#-5.1f", -7.3);}
int f_wzpljaf_prec3n(void){return test("%#-5.3f", -7.3);}
int f_wzpljaf_prec6n(void){return test("%#-5.6f", -7.3);}
//Floats with field width and allsign,~
int f_was_prec0p(void){return test("%+5.0f", 7.3);}
int f_was_prec1p(void){return test("%+5.1f", 7.3);}
int f_was_prec3p(void){return test("%+5.3f", 7.3);}
int f_was_prec6p(void){return test("%+5.6f", 7.3);}
int f_was_prec0n(void){return test("%+5.0f", -7.3);}
int f_was_prec1n(void){return test("%+5.1f", -7.3);}
int f_was_prec3n(void){return test("%+5.3f", -7.3);}
int f_was_prec6n(void){return test("%+5.6f", -7.3);}
//Floats with field width and zero padding and allsign,~
int f_wzpas_prec0p(void){return test("%+05.0f", 7.3);}
int f_wzpas_prec1p(void){return test("%+05.1f", 7.3);}
int f_wzpas_prec3p(void){return test("%+05.3f", 7.3);}
int f_wzpas_prec6p(void){return test("%+05.6f", 7.3);}
int f_wzpas_prec0n(void){return test("%+05.0f", -7.3);}
int f_wzpas_prec1n(void){return test("%+05.1f", -7.3);}
int f_wzpas_prec3n(void){return test("%+05.3f", -7.3);}
int f_wzpas_prec6n(void){return test("%+05.6f", -7.3);}
//Floats with field width and left justify and allsign,~
int f_wljas_prec0p(void){return test("%+-5.0f", 7.3);}
int f_wljas_prec1p(void){return test("%+-5.1f", 7.3);}
int f_wljas_prec3p(void){return test("%+-5.3f", 7.3);}
int f_wljas_prec6p(void){return test("%+-5.6f", 7.3);}
int f_wljas_prec0n(void){return test("%+-5.0f", -7.3);}
int f_wljas_prec1n(void){return test("%+-5.1f", -7.3);}
int f_wljas_prec3n(void){return test("%+-5.3f", -7.3);}
int f_wljas_prec6n(void){return test("%+-5.6f", -7.3);}
//Floats with field width and zero padding and left justify and allsign,~
int f_wzpljas_prec0p_ignoreflag(void){return test("%+-05.0f", 7.3);}
int f_wzpljas_prec1p_ignoreflag(void){return test("%+-05.1f", 7.3);}
int f_wzpljas_prec3p_ignoreflag(void){return test("%+-05.3f", 7.3);}
int f_wzpljas_prec6p_ignoreflag(void){return test("%+-05.6f", 7.3);}
int f_wzpljas_prec0n_ignoreflag(void){return test("%+-05.0f", -7.3);}
int f_wzpljas_prec1n_ignoreflag(void){return test("%+-05.1f", -7.3);}
int f_wzpljas_prec3n_ignoreflag(void){return test("%+-05.3f", -7.3);}
int f_wzpljas_prec6n_ignoreflag(void){return test("%+-05.6f", -7.3);}
//Floats with field width left justify, rev f order and allsign,~
int f_wzpljras_prec0p(void){return test("%-+5.0f", 7.3);}
int f_wzpljras_prec1p(void){return test("%-+5.1f", 7.3);}
int f_wzpljras_prec3p(void){return test("%-+5.3f", 7.3);}
int f_wzpljras_prec6p(void){return test("%-+5.6f", 7.3);}
int f_wzpljras_prec0n(void){return test("%-+5.0f", -7.3);}
int f_wzpljras_prec1n(void){return test("%-+5.1f", -7.3);}
int f_wzpljras_prec3n(void){return test("%-+5.3f", -7.3);}
int f_wzpljras_prec6n(void){return test("%-+5.6f", -7.3);}
//Floats with field width and left justify and altform and allsign,~
int f_wzpljafas_prec0p(void){return test("%+#-5.0f", 7.3);}
int f_wzpljafas_prec1p(void){return test("%+#-5.1f", 7.3);}
int f_wzpljafas_prec3p(void){return test("%+#-5.3f", 7.3);}
int f_wzpljafas_prec6p(void){return test("%+#-5.6f", 7.3);}
int f_wzpljafas_prec0n(void){return test("%+#-5.0f", -7.3);}
int f_wzpljafas_prec1n(void){return test("%+#-5.1f", -7.3);}
int f_wzpljafas_prec3n(void){return test("%+#-5.3f", -7.3);}
int f_wzpljafas_prec6n(void){return test("%+#-5.6f", -7.3);}
//Floats with field width and sp,~
int f_wsp_prec0p(void){return test("% 5.0f", 7.3);}
int f_wsp_prec1p(void){return test("% 5.1f", 7.3);}
int f_wsp_prec3p(void){return test("% 5.3f", 7.3);}
int f_wsp_prec6p(void){return test("% 5.6f", 7.3);}
int f_wsp_prec0n(void){return test("% 5.0f", -7.3);}
int f_wsp_prec1n(void){return test("% 5.1f", -7.3);}
int f_wsp_prec3n(void){return test("% 5.3f", -7.3);}
int f_wsp_prec6n(void){return test("% 5.6f", -7.3);}
//Floats with field width and zero padding and sp,~
int f_wzpsp_prec0p(void){return test("% 05.0f", 7.3);}
int f_wzpsp_prec1p(void){return test("% 05.1f", 7.3);}
int f_wzpsp_prec3p(void){return test("% 05.3f", 7.3);}
int f_wzpsp_prec6p(void){return test("% 05.6f", 7.3);}
int f_wzpsp_prec0n(void){return test("% 05.0f", -7.3);}
int f_wzpsp_prec1n(void){return test("% 05.1f", -7.3);}
int f_wzpsp_prec3n(void){return test("% 05.3f", -7.3);}
int f_wzpsp_prec6n(void){return test("% 05.6f", -7.3);}
//Floats with field width and left justify and sp,~
int f_wljsp_prec0p(void){return test("% -5.0f", 7.3);}
int f_wljsp_prec1p(void){return test("% -5.1f", 7.3);}
int f_wljsp_prec3p(void){return test("% -5.3f", 7.3);}
int f_wljsp_prec6p(void){return test("% -5.6f", 7.3);}
int f_wljsp_prec0n(void){return test("% -5.0f", -7.3);}
int f_wljsp_prec1n(void){return test("% -5.1f", -7.3);}
int f_wljsp_prec3n(void){return test("% -5.3f", -7.3);}
int f_wljsp_prec6n(void){return test("% -5.6f", -7.3);}
//Floats with field width and zero padding and left justify and sp,~
int f_wzpljsp_prec0p_ignoreflag(void){return test("% -05.0f", 7.3);}
int f_wzpljsp_prec1p_ignoreflag(void){return test("% -05.1f", 7.3);}
int f_wzpljsp_prec3p_ignoreflag(void){return test("% -05.3f", 7.3);}
int f_wzpljsp_prec6p_ignoreflag(void){return test("% -05.6f", 7.3);}
int f_wzpljsp_prec0n_ignoreflag(void){return test("% -05.0f", -7.3);}
int f_wzpljsp_prec1n_ignoreflag(void){return test("% -05.1f", -7.3);}
int f_wzpljsp_prec3n_ignoreflag(void){return test("% -05.3f", -7.3);}
int f_wzpljsp_prec6n_ignoreflag(void){return test("% -05.6f", -7.3);}
//Floats with field width left justify, rev f order and sp,~
int f_wzpljrsp_prec0p(void){return test("%- 5.0f", 7.3);}
int f_wzpljrsp_prec1p(void){return test("%- 5.1f", 7.3);}
int f_wzpljrsp_prec3p(void){return test("%- 5.3f", 7.3);}
int f_wzpljrsp_prec6p(void){return test("%- 5.6f", 7.3);}
int f_wzpljrsp_prec0n(void){return test("%- 5.0f", -7.3);}
int f_wzpljrsp_prec1n(void){return test("%- 5.1f", -7.3);}
int f_wzpljrsp_prec3n(void){return test("%- 5.3f", -7.3);}
int f_wzpljrsp_prec6n(void){return test("%- 5.6f", -7.3);}
//Floats with field width and left justify and altform and sp,~
int f_wzpljafsp_prec0p(void){return test("% #-5.0f", 7.3);}
int f_wzpljafsp_prec1p(void){return test("% #-5.1f", 7.3);}
int f_wzpljafsp_prec3p(void){return test("% #-5.3f", 7.3);}
int f_wzpljafsp_prec6p(void){return test("% #-5.6f", 7.3);}
int f_wzpljafsp_prec0n(void){return test("% #-5.0f", -7.3);}
int f_wzpljafsp_prec1n(void){return test("% #-5.1f", -7.3);}
int f_wzpljafsp_prec3n(void){return test("% #-5.3f", -7.3);}
int f_wzpljafsp_prec6n(void){return test("% #-5.6f", -7.3);}
//Floats with allsign and sp,~
int f_assp_prec0p_ignoreflag(void){return test("%+ .0f", 7.3);}
int f_assp_prec1p_ignoreflag(void){return test("%+ .1f", 7.3);}
int f_assp_prec3p_ignoreflag(void){return test("%+ .3f", 7.3);}
int f_assp_prec6p_ignoreflag(void){return test("%+ .6f", 7.3);}
int f_assp_prec0n_ignoreflag(void){return test("%+ .0f", -7.3);}
int f_assp_prec1n_ignoreflag(void){return test("%+ .1f", -7.3);}
int f_assp_prec3n_ignoreflag(void){return test("%+ .3f", -7.3);}
int f_assp_prec6n_ignoreflag(void){return test("%+ .6f", -7.3);}
//Floats with allsign and sp and rev flag order,~
int f_asspr_prec0p_ignoreflag(void){return test("% +.0f", 7.3);}
int f_asspr_prec1p_ignoreflag(void){return test("% +.1f", 7.3);}
int f_asspr_prec3p_ignoreflag(void){return test("% +.3f", 7.3);}
int f_asspr_prec6p_ignoreflag(void){return test("% +.6f", 7.3);}
int f_asspr_prec0n_ignoreflag(void){return test("% +.0f", -7.3);}
int f_asspr_prec1n_ignoreflag(void){return test("% +.1f", -7.3);}
int f_asspr_prec3n_ignoreflag(void){return test("% +.3f", -7.3);}
int f_asspr_prec6n_ignoreflag(void){return test("% +.6f", -7.3);}
//Floats whose precision exceeds their compiled literal precision
 int f_overprec_might_be_undefbehav_100(void){return test("%.100f", 0.237);}
 int f_overprec_might_be_undefbehav_32(void){return test("%.32f", 0.237);}
 int f_overprec_might_be_undefbehav_4(void){return test("%.4f", 0.237);}
 int f_overprec_might_be_undefbehav_1000(void){return test("%.4f", -0.106577568068517810765107851705167);}
 int f_overprec_might_be_undefbehav_10_from_0(void){return test("%.10f", 0.0);}
 int f_overprec_might_be_undefbehav_2000(void){return test("%.2000f", 623.28376510723481);}
 int f_overprec_might_be_undefbehav_dblmin(void){return test("%.2000f", DBL_MIN);}
 int f_overprec_might_be_undefbehav_ndblmin(void){return test("%.2000f", -DBL_MIN);}
//Floats at double max, double min
 int f_limits_dblmax_prec0_notmandatory(void){return test("%.0f", DBL_MAX);}
 int f_limits_dblmax_prec3_notmandatory(void){return test("%.3f", DBL_MAX);}
 int f_limits_dblmax_precd_notmandatory(void){return test("%f", DBL_MAX);}
 int f_limits_dblmax_prec8_notmandatory(void){return test("%.8f", DBL_MAX);}
 int f_stress_limits_dblmax_prec12_notmandatory(void){return test("%.12f", DBL_MAX);}
 int f_stress_limits_dblmax_prec16_notmandatory(void){return test("%.16f", DBL_MAX);}
 int f_stress_limits_dblmax_prec18_notmandatory(void){return test("%.18f", DBL_MAX);}
 int f_limits_ndblmax_prec0_notmandatory(void){return test("%.0f", -DBL_MAX);}
 int f_limits_ndblmax_prec3_notmandatory(void){return test("%.3f", -DBL_MAX);}
 int f_limits_ndblmax_precd_notmandatory(void){return test("%f", -DBL_MAX);}
 int f_limits_ndblmax_prec8_notmandatory(void){return test("%.8f", -DBL_MAX);}
 int f_stress_limits_ndblmax_prec12_notmandatory(void){return test("%.12f", -DBL_MAX);}
 int f_stress_limits_ndblmax_prec16_notmandatory(void){return test("%.16f", -DBL_MAX);}
 int f_stress_limits_ndblmax_prec18_notmandatory(void){return test("%.18f", -DBL_MAX);}
int f_limits_dblmin_prec0(void){return test("%.0f", DBL_MIN);}
int f_limits_dblmin_prec3(void){return test("%.3f", DBL_MIN);}
int f_limits_dblmin_precd(void){return test("%f", DBL_MIN);}
int f_limits_dblmin_prec8(void){return test("%.8f", DBL_MIN);}
int f_stress_limits_dblmin_prec12(void){return test("%.12f", DBL_MIN);}
int f_stress_limits_dblmin_prec16(void){return test("%.16f", DBL_MIN);}
int f_stress_limits_dblmin_prec18(void){return test("%.18f", DBL_MIN);}
int f_limits_ndblmin_prec0(void){return test("%.0f", -DBL_MIN);}
int f_limits_ndblmin_prec3(void){return test("%.3f", -DBL_MIN);}
int f_limits_ndblmin_precd(void){return test("%f", -DBL_MIN);}
int f_limits_ndblmin_prec8(void){return test("%.8f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec12(void){return test("%.12f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec16(void){return test("%.16f", -DBL_MIN);}
int f_stress_limits_ndblmin_prec18(void){return test("%.18f", -DBL_MIN);}

}
