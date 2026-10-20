/* ------------------------------------------------------------
author: "nyanpasu64"
copyright: "nyanpasu64"
license: "BSD"
name: "snes-echo"
version: "0."
Code generated with Faust 2.88.0 (https://faust.grame.fr)
Compilation options: -lang cpp -fpga-mem-th 4 -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>
#ifndef FAUST_INT_WRAP
#define FAUST_INT_WRAP
inline int faust_wrap_add(int a, int b) { return int((unsigned int)a + (unsigned int)b); }
inline int faust_wrap_sub(int a, int b) { return int((unsigned int)a - (unsigned int)b); }
inline int faust_wrap_mul(int a, int b) { return int((unsigned int)a * (unsigned int)b); }
#endif


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	float fVec0[2];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fVslider1;
	int IOTA0;
	float fVec1[65536];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fVec2[128];
	float fVec3[2];
	float fVec4[2];
	float fVec5[2];
	float fVec6[2];
	float fVec7[2];
	float fVec8[2];
	float fVec9[2];
	FAUSTFLOAT fVslider2;
	float fConst2;
	int iConst3;
	int iConst4;
	float fVec10[2];
	float fVec11[2];
	float fVec12[2];
	float fVec13[2];
	float fVec14[2];
	float fVec15[2];
	float fVec16[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	FAUSTFLOAT fVslider3;
	float fConst20;
	float fConst21;
	int iConst22;
	int iConst23;
	float fVec17[2];
	float fVec18[2];
	float fVec19[2];
	float fVec20[2];
	float fVec21[2];
	float fVec22[2];
	float fVec23[2];
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fConst38;
	FAUSTFLOAT fVslider4;
	float fConst39;
	float fConst40;
	int iConst41;
	int iConst42;
	float fVec24[2];
	float fVec25[2];
	float fVec26[2];
	float fVec27[2];
	float fVec28[2];
	float fVec29[2];
	float fVec30[2];
	float fConst43;
	float fConst44;
	float fConst45;
	float fConst46;
	float fConst47;
	float fConst48;
	float fConst49;
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	FAUSTFLOAT fVslider5;
	float fConst58;
	float fConst59;
	int iConst60;
	int iConst61;
	float fVec31[2];
	float fVec32[2];
	float fVec33[2];
	float fVec34[2];
	float fVec35[2];
	float fVec36[2];
	float fVec37[2];
	float fConst62;
	float fConst63;
	float fConst64;
	float fConst65;
	float fConst66;
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fConst76;
	FAUSTFLOAT fVslider6;
	float fConst77;
	float fConst78;
	int iConst79;
	int iConst80;
	float fVec38[2];
	float fVec39[2];
	float fVec40[2];
	float fVec41[2];
	float fVec42[2];
	float fVec43[2];
	float fVec44[2];
	float fConst81;
	float fConst82;
	float fConst83;
	float fConst84;
	float fConst85;
	float fConst86;
	float fConst87;
	float fConst88;
	float fConst89;
	float fConst90;
	float fConst91;
	float fConst92;
	float fConst93;
	float fConst94;
	float fConst95;
	FAUSTFLOAT fVslider7;
	float fConst96;
	float fConst97;
	int iConst98;
	int iConst99;
	float fVec45[2];
	float fVec46[2];
	float fVec47[2];
	float fVec48[2];
	float fVec49[2];
	float fVec50[2];
	float fVec51[2];
	float fConst100;
	float fConst101;
	float fConst102;
	float fConst103;
	float fConst104;
	float fConst105;
	float fConst106;
	float fConst107;
	float fConst108;
	float fConst109;
	float fConst110;
	float fConst111;
	float fConst112;
	float fConst113;
	float fConst114;
	FAUSTFLOAT fVslider8;
	float fConst115;
	float fConst116;
	int iConst117;
	int iConst118;
	float fVec52[2];
	float fVec53[2];
	float fVec54[2];
	float fVec55[2];
	float fVec56[2];
	float fVec57[2];
	float fVec58[2];
	float fConst119;
	float fConst120;
	float fConst121;
	float fConst122;
	float fConst123;
	float fConst124;
	float fConst125;
	float fConst126;
	float fConst127;
	float fConst128;
	float fConst129;
	float fConst130;
	float fConst131;
	float fConst132;
	float fConst133;
	FAUSTFLOAT fVslider9;
	float fRec0[2];
	float fVec59[64];
	int iConst134;
	int iConst135;
	int iConst136;
	int iConst137;
	int iConst138;
	int iConst139;
	int iConst140;
	int iConst141;
	int iConst142;
	float fRec1[2];
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fVslider11;
	FAUSTFLOAT fCheckbox7;
	float fVec60[2];
	float fVec61[65536];
	float fVec62[128];
	float fVec63[2];
	float fVec64[2];
	float fVec65[2];
	float fVec66[2];
	float fVec67[2];
	float fVec68[2];
	float fVec69[2];
	float fVec70[2];
	float fVec71[2];
	float fVec72[2];
	float fVec73[2];
	float fVec74[2];
	float fVec75[2];
	float fVec76[2];
	float fVec77[2];
	float fVec78[2];
	float fVec79[2];
	float fVec80[2];
	float fVec81[2];
	float fVec82[2];
	float fVec83[2];
	float fVec84[2];
	float fVec85[2];
	float fVec86[2];
	float fVec87[2];
	float fVec88[2];
	float fVec89[2];
	float fVec90[2];
	float fVec91[2];
	float fVec92[2];
	float fVec93[2];
	float fVec94[2];
	float fVec95[2];
	float fVec96[2];
	float fVec97[2];
	float fVec98[2];
	float fVec99[2];
	float fVec100[2];
	float fVec101[2];
	float fVec102[2];
	float fVec103[2];
	float fVec104[2];
	float fVec105[2];
	float fVec106[2];
	float fVec107[2];
	float fVec108[2];
	float fVec109[2];
	float fVec110[2];
	float fVec111[2];
	float fVec112[2];
	float fVec113[2];
	float fVec114[2];
	float fVec115[2];
	float fVec116[2];
	float fVec117[2];
	float fVec118[2];
	float fRec2[2];
	float fVec119[64];
	float fRec3[2];
	
 public:
	mydsp() {
	}
	
	mydsp(const mydsp&) = default;
	
	virtual ~mydsp() = default;
	
	mydsp& operator=(const mydsp&) = default;
	
	void metadata(Meta* m) { 
		m->declare("author", "nyanpasu64");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.23.0");
		m->declare("compile_options", "-lang cpp -fpga-mem-th 4 -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("copyright", "nyanpasu64");
		m->declare("delays.lib/fdelaylti:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "snes_echo.dsp");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LicenseRef-LGPL-2.1-or-later-with-Faust-exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "snes-echo");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("version", "0.");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(8.0f, 3.125e-05f * std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate))));
		fConst1 = 512.0f * fConst0;
		fConst2 = fConst0 + 28.500006f;
		iConst3 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst2)));
		iConst4 = faust_wrap_add(iConst3, 1);
		fConst5 = std::floor(fConst2);
		fConst6 = fConst5 + (-31.0f - fConst0);
		fConst7 = fConst6 * (fConst5 + (-3e+01f - fConst0));
		fConst8 = fConst7 * (fConst5 + (-29.0f - fConst0));
		fConst9 = fConst8 * (fConst5 + (-28.0f - fConst0));
		fConst10 = fConst9 * (fConst5 + (-27.0f - fConst0));
		fConst11 = fConst10 * (fConst5 + (-26.0f - fConst0));
		fConst12 = 2.4801588e-05f * fConst11 * (fConst5 + (-25.0f - fConst0));
		fConst13 = 0.0001984127f * fConst11;
		fConst14 = 0.0013888889f * fConst10;
		fConst15 = 0.008333334f * fConst9;
		fConst16 = 0.041666668f * fConst8;
		fConst17 = 0.16666667f * fConst7;
		fConst18 = 0.5f * fConst6;
		fConst19 = fConst0 + (32.0f - fConst5);
		fConst20 = 2.0f * fConst0;
		fConst21 = fConst20 + 28.500006f;
		iConst22 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst21)));
		iConst23 = faust_wrap_add(iConst22, 1);
		fConst24 = std::floor(fConst21);
		fConst25 = fConst24 + (-31.0f - fConst20);
		fConst26 = fConst25 * (fConst24 + (-3e+01f - fConst20));
		fConst27 = fConst26 * (fConst24 + (-29.0f - fConst20));
		fConst28 = fConst27 * (fConst24 + (-28.0f - fConst20));
		fConst29 = fConst28 * (fConst24 + (-27.0f - fConst20));
		fConst30 = fConst29 * (fConst24 + (-26.0f - fConst20));
		fConst31 = 2.4801588e-05f * fConst30 * (fConst24 + (-25.0f - fConst20));
		fConst32 = 0.0001984127f * fConst30;
		fConst33 = 0.0013888889f * fConst29;
		fConst34 = 0.008333334f * fConst28;
		fConst35 = 0.041666668f * fConst27;
		fConst36 = 0.16666667f * fConst26;
		fConst37 = 0.5f * fConst25;
		fConst38 = fConst20 + (32.0f - fConst24);
		fConst39 = 3.0f * fConst0;
		fConst40 = fConst39 + 28.500006f;
		iConst41 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst40)));
		iConst42 = faust_wrap_add(iConst41, 1);
		fConst43 = std::floor(fConst40);
		fConst44 = fConst43 + (-31.0f - fConst39);
		fConst45 = fConst44 * (fConst43 + (-3e+01f - fConst39));
		fConst46 = fConst45 * (fConst43 + (-29.0f - fConst39));
		fConst47 = fConst46 * (fConst43 + (-28.0f - fConst39));
		fConst48 = fConst47 * (fConst43 + (-27.0f - fConst39));
		fConst49 = fConst48 * (fConst43 + (-26.0f - fConst39));
		fConst50 = 2.4801588e-05f * fConst49 * (fConst43 + (-25.0f - fConst39));
		fConst51 = 0.0001984127f * fConst49;
		fConst52 = 0.0013888889f * fConst48;
		fConst53 = 0.008333334f * fConst47;
		fConst54 = 0.041666668f * fConst46;
		fConst55 = 0.16666667f * fConst45;
		fConst56 = 0.5f * fConst44;
		fConst57 = fConst39 + (32.0f - fConst43);
		fConst58 = 4.0f * fConst0;
		fConst59 = fConst58 + 28.500006f;
		iConst60 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst59)));
		iConst61 = faust_wrap_add(iConst60, 1);
		fConst62 = std::floor(fConst59);
		fConst63 = fConst62 + (-31.0f - fConst58);
		fConst64 = fConst63 * (fConst62 + (-3e+01f - fConst58));
		fConst65 = fConst64 * (fConst62 + (-29.0f - fConst58));
		fConst66 = fConst65 * (fConst62 + (-28.0f - fConst58));
		fConst67 = fConst66 * (fConst62 + (-27.0f - fConst58));
		fConst68 = fConst67 * (fConst62 + (-26.0f - fConst58));
		fConst69 = 2.4801588e-05f * fConst68 * (fConst62 + (-25.0f - fConst58));
		fConst70 = 0.0001984127f * fConst68;
		fConst71 = 0.0013888889f * fConst67;
		fConst72 = 0.008333334f * fConst66;
		fConst73 = 0.041666668f * fConst65;
		fConst74 = 0.16666667f * fConst64;
		fConst75 = 0.5f * fConst63;
		fConst76 = fConst58 + (32.0f - fConst62);
		fConst77 = 5.0f * fConst0;
		fConst78 = fConst77 + 28.500006f;
		iConst79 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst78)));
		iConst80 = faust_wrap_add(iConst79, 1);
		fConst81 = std::floor(fConst78);
		fConst82 = fConst81 + (-31.0f - fConst77);
		fConst83 = fConst82 * (fConst81 + (-3e+01f - fConst77));
		fConst84 = fConst83 * (fConst81 + (-29.0f - fConst77));
		fConst85 = fConst84 * (fConst81 + (-28.0f - fConst77));
		fConst86 = fConst85 * (fConst81 + (-27.0f - fConst77));
		fConst87 = fConst86 * (fConst81 + (-26.0f - fConst77));
		fConst88 = 2.4801588e-05f * fConst87 * (fConst81 + (-25.0f - fConst77));
		fConst89 = 0.0001984127f * fConst87;
		fConst90 = 0.0013888889f * fConst86;
		fConst91 = 0.008333334f * fConst85;
		fConst92 = 0.041666668f * fConst84;
		fConst93 = 0.16666667f * fConst83;
		fConst94 = 0.5f * fConst82;
		fConst95 = fConst77 + (32.0f - fConst81);
		fConst96 = 6.0f * fConst0;
		fConst97 = fConst96 + 28.500006f;
		iConst98 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst97)));
		iConst99 = faust_wrap_add(iConst98, 1);
		fConst100 = std::floor(fConst97);
		fConst101 = fConst100 + (-31.0f - fConst96);
		fConst102 = fConst101 * (fConst100 + (-3e+01f - fConst96));
		fConst103 = fConst102 * (fConst100 + (-29.0f - fConst96));
		fConst104 = fConst103 * (fConst100 + (-28.0f - fConst96));
		fConst105 = fConst104 * (fConst100 + (-27.0f - fConst96));
		fConst106 = fConst105 * (fConst100 + (-26.0f - fConst96));
		fConst107 = 2.4801588e-05f * fConst106 * (fConst100 + (-25.0f - fConst96));
		fConst108 = 0.0001984127f * fConst106;
		fConst109 = 0.0013888889f * fConst105;
		fConst110 = 0.008333334f * fConst104;
		fConst111 = 0.041666668f * fConst103;
		fConst112 = 0.16666667f * fConst102;
		fConst113 = 0.5f * fConst101;
		fConst114 = fConst96 + (32.0f - fConst100);
		fConst115 = 7.0f * fConst0;
		fConst116 = fConst115 + 28.500006f;
		iConst117 = std::min<int>(96, std::max<int>(0, static_cast<int>(fConst116)));
		iConst118 = faust_wrap_add(iConst117, 1);
		fConst119 = std::floor(fConst116);
		fConst120 = fConst119 + (-31.0f - fConst115);
		fConst121 = fConst120 * (fConst119 + (-3e+01f - fConst115));
		fConst122 = fConst121 * (fConst119 + (-29.0f - fConst115));
		fConst123 = fConst122 * (fConst119 + (-28.0f - fConst115));
		fConst124 = fConst123 * (fConst119 + (-27.0f - fConst115));
		fConst125 = fConst124 * (fConst119 + (-26.0f - fConst115));
		fConst126 = 2.4801588e-05f * fConst125 * (fConst119 + (-25.0f - fConst115));
		fConst127 = 0.0001984127f * fConst125;
		fConst128 = 0.0013888889f * fConst124;
		fConst129 = 0.008333334f * fConst123;
		fConst130 = 0.041666668f * fConst122;
		fConst131 = 0.16666667f * fConst121;
		fConst132 = 0.5f * fConst120;
		fConst133 = fConst115 + (32.0f - fConst119);
		iConst134 = std::max<int>(static_cast<int>(fConst0), 1);
		iConst135 = std::min<int>(7, std::max<int>(0, faust_wrap_add(iConst134, -1)));
		iConst136 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, iConst134)));
		iConst137 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, faust_wrap_mul(2, iConst134))));
		iConst138 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, faust_wrap_mul(3, iConst134))));
		iConst139 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, faust_wrap_mul(4, iConst134))));
		iConst140 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, faust_wrap_mul(5, iConst134))));
		iConst141 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, faust_wrap_mul(6, iConst134))));
		iConst142 = faust_wrap_add(iConst135, std::min<int>(56, std::max<int>(0, faust_wrap_mul(7, iConst134))));
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider0 = static_cast<FAUSTFLOAT>(5.0f);
		fCheckbox1 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox2 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider1 = static_cast<FAUSTFLOAT>(7e+01f);
		fVslider2 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider3 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider4 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider5 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider6 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider7 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider8 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider9 = static_cast<FAUSTFLOAT>(127.0f);
		fCheckbox3 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox4 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider10 = static_cast<FAUSTFLOAT>(25.0f);
		fCheckbox5 = static_cast<FAUSTFLOAT>(0.0f);
		fCheckbox6 = static_cast<FAUSTFLOAT>(0.0f);
		fVslider11 = static_cast<FAUSTFLOAT>(63.0f);
		fCheckbox7 = static_cast<FAUSTFLOAT>(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = faust_wrap_add(l0, 1)) {
			fVec0[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 65536; l1 = faust_wrap_add(l1, 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 128; l2 = faust_wrap_add(l2, 1)) {
			fVec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = faust_wrap_add(l3, 1)) {
			fVec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = faust_wrap_add(l4, 1)) {
			fVec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = faust_wrap_add(l5, 1)) {
			fVec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = faust_wrap_add(l6, 1)) {
			fVec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = faust_wrap_add(l7, 1)) {
			fVec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = faust_wrap_add(l8, 1)) {
			fVec8[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = faust_wrap_add(l9, 1)) {
			fVec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = faust_wrap_add(l10, 1)) {
			fVec10[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = faust_wrap_add(l11, 1)) {
			fVec11[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = faust_wrap_add(l12, 1)) {
			fVec12[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = faust_wrap_add(l13, 1)) {
			fVec13[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = faust_wrap_add(l14, 1)) {
			fVec14[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = faust_wrap_add(l15, 1)) {
			fVec15[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = faust_wrap_add(l16, 1)) {
			fVec16[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = faust_wrap_add(l17, 1)) {
			fVec17[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = faust_wrap_add(l18, 1)) {
			fVec18[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = faust_wrap_add(l19, 1)) {
			fVec19[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = faust_wrap_add(l20, 1)) {
			fVec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = faust_wrap_add(l21, 1)) {
			fVec21[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = faust_wrap_add(l22, 1)) {
			fVec22[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = faust_wrap_add(l23, 1)) {
			fVec23[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = faust_wrap_add(l24, 1)) {
			fVec24[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = faust_wrap_add(l25, 1)) {
			fVec25[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = faust_wrap_add(l26, 1)) {
			fVec26[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = faust_wrap_add(l27, 1)) {
			fVec27[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = faust_wrap_add(l28, 1)) {
			fVec28[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = faust_wrap_add(l29, 1)) {
			fVec29[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = faust_wrap_add(l30, 1)) {
			fVec30[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = faust_wrap_add(l31, 1)) {
			fVec31[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = faust_wrap_add(l32, 1)) {
			fVec32[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = faust_wrap_add(l33, 1)) {
			fVec33[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = faust_wrap_add(l34, 1)) {
			fVec34[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = faust_wrap_add(l35, 1)) {
			fVec35[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = faust_wrap_add(l36, 1)) {
			fVec36[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = faust_wrap_add(l37, 1)) {
			fVec37[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = faust_wrap_add(l38, 1)) {
			fVec38[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = faust_wrap_add(l39, 1)) {
			fVec39[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = faust_wrap_add(l40, 1)) {
			fVec40[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = faust_wrap_add(l41, 1)) {
			fVec41[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = faust_wrap_add(l42, 1)) {
			fVec42[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = faust_wrap_add(l43, 1)) {
			fVec43[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = faust_wrap_add(l44, 1)) {
			fVec44[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = faust_wrap_add(l45, 1)) {
			fVec45[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = faust_wrap_add(l46, 1)) {
			fVec46[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = faust_wrap_add(l47, 1)) {
			fVec47[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = faust_wrap_add(l48, 1)) {
			fVec48[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = faust_wrap_add(l49, 1)) {
			fVec49[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = faust_wrap_add(l50, 1)) {
			fVec50[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = faust_wrap_add(l51, 1)) {
			fVec51[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = faust_wrap_add(l52, 1)) {
			fVec52[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = faust_wrap_add(l53, 1)) {
			fVec53[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = faust_wrap_add(l54, 1)) {
			fVec54[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = faust_wrap_add(l55, 1)) {
			fVec55[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = faust_wrap_add(l56, 1)) {
			fVec56[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = faust_wrap_add(l57, 1)) {
			fVec57[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = faust_wrap_add(l58, 1)) {
			fVec58[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = faust_wrap_add(l59, 1)) {
			fRec0[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 64; l60 = faust_wrap_add(l60, 1)) {
			fVec59[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = faust_wrap_add(l61, 1)) {
			fRec1[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = faust_wrap_add(l62, 1)) {
			fVec60[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 65536; l63 = faust_wrap_add(l63, 1)) {
			fVec61[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 128; l64 = faust_wrap_add(l64, 1)) {
			fVec62[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = faust_wrap_add(l65, 1)) {
			fVec63[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = faust_wrap_add(l66, 1)) {
			fVec64[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = faust_wrap_add(l67, 1)) {
			fVec65[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = faust_wrap_add(l68, 1)) {
			fVec66[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = faust_wrap_add(l69, 1)) {
			fVec67[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = faust_wrap_add(l70, 1)) {
			fVec68[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = faust_wrap_add(l71, 1)) {
			fVec69[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = faust_wrap_add(l72, 1)) {
			fVec70[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = faust_wrap_add(l73, 1)) {
			fVec71[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2; l74 = faust_wrap_add(l74, 1)) {
			fVec72[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = faust_wrap_add(l75, 1)) {
			fVec73[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = faust_wrap_add(l76, 1)) {
			fVec74[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = faust_wrap_add(l77, 1)) {
			fVec75[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = faust_wrap_add(l78, 1)) {
			fVec76[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = faust_wrap_add(l79, 1)) {
			fVec77[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = faust_wrap_add(l80, 1)) {
			fVec78[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = faust_wrap_add(l81, 1)) {
			fVec79[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = faust_wrap_add(l82, 1)) {
			fVec80[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 2; l83 = faust_wrap_add(l83, 1)) {
			fVec81[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 2; l84 = faust_wrap_add(l84, 1)) {
			fVec82[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = faust_wrap_add(l85, 1)) {
			fVec83[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = faust_wrap_add(l86, 1)) {
			fVec84[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = faust_wrap_add(l87, 1)) {
			fVec85[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = faust_wrap_add(l88, 1)) {
			fVec86[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = faust_wrap_add(l89, 1)) {
			fVec87[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2; l90 = faust_wrap_add(l90, 1)) {
			fVec88[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = faust_wrap_add(l91, 1)) {
			fVec89[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = faust_wrap_add(l92, 1)) {
			fVec90[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 2; l93 = faust_wrap_add(l93, 1)) {
			fVec91[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = faust_wrap_add(l94, 1)) {
			fVec92[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = faust_wrap_add(l95, 1)) {
			fVec93[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 2; l96 = faust_wrap_add(l96, 1)) {
			fVec94[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = faust_wrap_add(l97, 1)) {
			fVec95[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 2; l98 = faust_wrap_add(l98, 1)) {
			fVec96[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 2; l99 = faust_wrap_add(l99, 1)) {
			fVec97[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = faust_wrap_add(l100, 1)) {
			fVec98[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = faust_wrap_add(l101, 1)) {
			fVec99[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 2; l102 = faust_wrap_add(l102, 1)) {
			fVec100[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = faust_wrap_add(l103, 1)) {
			fVec101[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2; l104 = faust_wrap_add(l104, 1)) {
			fVec102[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = faust_wrap_add(l105, 1)) {
			fVec103[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2; l106 = faust_wrap_add(l106, 1)) {
			fVec104[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = faust_wrap_add(l107, 1)) {
			fVec105[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 2; l108 = faust_wrap_add(l108, 1)) {
			fVec106[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = faust_wrap_add(l109, 1)) {
			fVec107[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 2; l110 = faust_wrap_add(l110, 1)) {
			fVec108[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = faust_wrap_add(l111, 1)) {
			fVec109[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 2; l112 = faust_wrap_add(l112, 1)) {
			fVec110[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = faust_wrap_add(l113, 1)) {
			fVec111[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 2; l114 = faust_wrap_add(l114, 1)) {
			fVec112[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = faust_wrap_add(l115, 1)) {
			fVec113[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = faust_wrap_add(l116, 1)) {
			fVec114[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 2; l117 = faust_wrap_add(l117, 1)) {
			fVec115[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 2; l118 = faust_wrap_add(l118, 1)) {
			fVec116[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 2; l119 = faust_wrap_add(l119, 1)) {
			fVec117[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = faust_wrap_add(l120, 1)) {
			fVec118[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2; l121 = faust_wrap_add(l121, 1)) {
			fRec2[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 64; l122 = faust_wrap_add(l122, 1)) {
			fVec119[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 2; l123 = faust_wrap_add(l123, 1)) {
			fRec3[l123] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("snes-echo");
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fVslider0, "0", "");
		ui_interface->addVerticalSlider("Echo blocks (16ms)", &fVslider0, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fCheckbox0, "1", "");
		ui_interface->addCheckButton("Bypass Echo", &fCheckbox0);
		ui_interface->declare(&fCheckbox7, "2", "");
		ui_interface->addCheckButton("Normalize Volumes", &fCheckbox7);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("Dry Volume");
		ui_interface->declare(&fVslider11, "1", "");
		ui_interface->addVerticalSlider("Dry Volume", &fVslider11, FAUSTFLOAT(63.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fCheckbox6, "2", "");
		ui_interface->addCheckButton("Negative", &fCheckbox6);
		ui_interface->declare(&fCheckbox5, "3", "");
		ui_interface->addCheckButton("Surround", &fCheckbox5);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openVerticalBox("Wet Volume");
		ui_interface->declare(&fVslider10, "1", "");
		ui_interface->addVerticalSlider("Wet Volume", &fVslider10, FAUSTFLOAT(25.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fCheckbox4, "2", "");
		ui_interface->addCheckButton("Negative", &fCheckbox4);
		ui_interface->declare(&fCheckbox3, "3", "");
		ui_interface->addCheckButton("Surround", &fCheckbox3);
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openVerticalBox("Echo Feedback");
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->addVerticalSlider("Echo Feedback", &fVslider1, FAUSTFLOAT(7e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fCheckbox2, "2", "");
		ui_interface->addCheckButton("Negative", &fCheckbox2);
		ui_interface->declare(&fCheckbox1, "3", "");
		ui_interface->addCheckButton("Surround (not on SNES)", &fCheckbox1);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("FIR Filter");
		ui_interface->addVerticalSlider("0", &fVslider9, FAUSTFLOAT(127.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("1", &fVslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("2", &fVslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("3", &fVslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("4", &fVslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("5", &fVslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("6", &fVslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->addVerticalSlider("7", &fVslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-128.0f), FAUSTFLOAT(127.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = static_cast<float>(fCheckbox0) == 0.0f;
		float fSlow1 = std::rint(static_cast<float>(fVslider0));
		int iSlow2 = fSlow1 == 0.0f;
		float fSlow3 = std::rint(static_cast<float>(fVslider1) * static_cast<float>(((static_cast<int>(static_cast<float>(fCheckbox2))) ? -1 : 1)));
		float fSlow4 = 0.0078125f * fSlow3 * static_cast<float>(((static_cast<int>(static_cast<float>(fCheckbox1))) ? -1 : 1));
		int iSlow5 = static_cast<int>(std::min<float>(131072.0f, std::max<float>(0.0f, std::rint(fConst1 * fSlow1) + -33.0f)));
		float fSlow6 = std::rint(static_cast<float>(fVslider2));
		float fSlow7 = std::rint(static_cast<float>(fVslider3));
		float fSlow8 = std::rint(static_cast<float>(fVslider4));
		float fSlow9 = std::rint(static_cast<float>(fVslider5));
		float fSlow10 = std::rint(static_cast<float>(fVslider6));
		float fSlow11 = std::rint(static_cast<float>(fVslider7));
		float fSlow12 = std::rint(static_cast<float>(fVslider8));
		float fSlow13 = std::rint(static_cast<float>(fVslider9));
		float fSlow14 = std::rint(static_cast<float>(fVslider10) * static_cast<float>(((static_cast<int>(static_cast<float>(fCheckbox4))) ? -1 : 1)));
		float fSlow15 = fSlow14 * static_cast<float>(((static_cast<int>(static_cast<float>(fCheckbox3))) ? -1 : 1));
		float fSlow16 = std::rint(static_cast<float>(fVslider11) * static_cast<float>(((static_cast<int>(static_cast<float>(fCheckbox6))) ? -1 : 1)));
		float fSlow17 = fSlow16 * static_cast<float>(((static_cast<int>(static_cast<float>(fCheckbox5))) ? -1 : 1));
		float fSlow18 = 0.0078125f * ((static_cast<int>(static_cast<float>(fCheckbox7))) ? 128.0f / std::max<float>(std::max<float>(std::max<float>(std::fabs(fSlow17), std::fabs(fSlow16)), std::max<float>(std::fabs(fSlow15), std::fabs(fSlow14))), 1.0f) : 1.0f);
		float fSlow19 = 0.0078125f * fSlow3;
		for (int i0 = 0; i0 < count; i0 = faust_wrap_add(i0, 1)) {
			float fTemp0 = static_cast<float>(input0[i0]);
			fVec0[0] = fTemp0;
			fVec1[IOTA0 & 65535] = std::min<float>(std::max<float>(fTemp0 + fSlow4 * fRec0[1], -1.0f), 1.0f);
			float fTemp1 = fVec1[(faust_wrap_sub(IOTA0, iSlow5)) & 65535];
			fVec2[IOTA0 & 127] = fTemp1;
			float fTemp2 = fVec2[(faust_wrap_sub(IOTA0, 28)) & 127];
			float fTemp3 = fVec2[(faust_wrap_sub(IOTA0, 29)) & 127] - fTemp2;
			fVec3[0] = fTemp3;
			float fTemp4 = fTemp3 - fVec3[1];
			fVec4[0] = fTemp4;
			float fTemp5 = fTemp4 - fVec4[1];
			fVec5[0] = fTemp5;
			float fTemp6 = fTemp5 - fVec5[1];
			fVec6[0] = fTemp6;
			float fTemp7 = fTemp6 - fVec6[1];
			fVec7[0] = fTemp7;
			float fTemp8 = fTemp7 - fVec7[1];
			fVec8[0] = fTemp8;
			float fTemp9 = fTemp8 - fVec8[1];
			fVec9[0] = fTemp9;
			float fTemp10 = fVec2[(faust_wrap_sub(IOTA0, iConst3)) & 127];
			float fTemp11 = fTemp10 - fVec2[(faust_wrap_sub(IOTA0, iConst4)) & 127];
			fVec10[0] = fTemp11;
			float fTemp12 = fTemp11 - fVec10[1];
			fVec11[0] = fTemp12;
			float fTemp13 = fTemp12 - fVec11[1];
			fVec12[0] = fTemp13;
			float fTemp14 = fTemp13 - fVec12[1];
			fVec13[0] = fTemp14;
			float fTemp15 = fTemp14 - fVec13[1];
			fVec14[0] = fTemp15;
			float fTemp16 = fTemp15 - fVec14[1];
			fVec15[0] = fTemp16;
			float fTemp17 = fTemp16 - fVec15[1];
			fVec16[0] = fTemp17;
			float fTemp18 = fVec2[(faust_wrap_sub(IOTA0, iConst22)) & 127];
			float fTemp19 = fTemp18 - fVec2[(faust_wrap_sub(IOTA0, iConst23)) & 127];
			fVec17[0] = fTemp19;
			float fTemp20 = fTemp19 - fVec17[1];
			fVec18[0] = fTemp20;
			float fTemp21 = fTemp20 - fVec18[1];
			fVec19[0] = fTemp21;
			float fTemp22 = fTemp21 - fVec19[1];
			fVec20[0] = fTemp22;
			float fTemp23 = fTemp22 - fVec20[1];
			fVec21[0] = fTemp23;
			float fTemp24 = fTemp23 - fVec21[1];
			fVec22[0] = fTemp24;
			float fTemp25 = fTemp24 - fVec22[1];
			fVec23[0] = fTemp25;
			float fTemp26 = fVec2[(faust_wrap_sub(IOTA0, iConst41)) & 127];
			float fTemp27 = fTemp26 - fVec2[(faust_wrap_sub(IOTA0, iConst42)) & 127];
			fVec24[0] = fTemp27;
			float fTemp28 = fTemp27 - fVec24[1];
			fVec25[0] = fTemp28;
			float fTemp29 = fTemp28 - fVec25[1];
			fVec26[0] = fTemp29;
			float fTemp30 = fTemp29 - fVec26[1];
			fVec27[0] = fTemp30;
			float fTemp31 = fTemp30 - fVec27[1];
			fVec28[0] = fTemp31;
			float fTemp32 = fTemp31 - fVec28[1];
			fVec29[0] = fTemp32;
			float fTemp33 = fTemp32 - fVec29[1];
			fVec30[0] = fTemp33;
			float fTemp34 = fVec2[(faust_wrap_sub(IOTA0, iConst60)) & 127];
			float fTemp35 = fTemp34 - fVec2[(faust_wrap_sub(IOTA0, iConst61)) & 127];
			fVec31[0] = fTemp35;
			float fTemp36 = fTemp35 - fVec31[1];
			fVec32[0] = fTemp36;
			float fTemp37 = fTemp36 - fVec32[1];
			fVec33[0] = fTemp37;
			float fTemp38 = fTemp37 - fVec33[1];
			fVec34[0] = fTemp38;
			float fTemp39 = fTemp38 - fVec34[1];
			fVec35[0] = fTemp39;
			float fTemp40 = fTemp39 - fVec35[1];
			fVec36[0] = fTemp40;
			float fTemp41 = fTemp40 - fVec36[1];
			fVec37[0] = fTemp41;
			float fTemp42 = fVec2[(faust_wrap_sub(IOTA0, iConst79)) & 127];
			float fTemp43 = fTemp42 - fVec2[(faust_wrap_sub(IOTA0, iConst80)) & 127];
			fVec38[0] = fTemp43;
			float fTemp44 = fTemp43 - fVec38[1];
			fVec39[0] = fTemp44;
			float fTemp45 = fTemp44 - fVec39[1];
			fVec40[0] = fTemp45;
			float fTemp46 = fTemp45 - fVec40[1];
			fVec41[0] = fTemp46;
			float fTemp47 = fTemp46 - fVec41[1];
			fVec42[0] = fTemp47;
			float fTemp48 = fTemp47 - fVec42[1];
			fVec43[0] = fTemp48;
			float fTemp49 = fTemp48 - fVec43[1];
			fVec44[0] = fTemp49;
			float fTemp50 = fVec2[(faust_wrap_sub(IOTA0, iConst98)) & 127];
			float fTemp51 = fTemp50 - fVec2[(faust_wrap_sub(IOTA0, iConst99)) & 127];
			fVec45[0] = fTemp51;
			float fTemp52 = fTemp51 - fVec45[1];
			fVec46[0] = fTemp52;
			float fTemp53 = fTemp52 - fVec46[1];
			fVec47[0] = fTemp53;
			float fTemp54 = fTemp53 - fVec47[1];
			fVec48[0] = fTemp54;
			float fTemp55 = fTemp54 - fVec48[1];
			fVec49[0] = fTemp55;
			float fTemp56 = fTemp55 - fVec49[1];
			fVec50[0] = fTemp56;
			float fTemp57 = fTemp56 - fVec50[1];
			fVec51[0] = fTemp57;
			float fTemp58 = fVec2[(faust_wrap_sub(IOTA0, iConst117)) & 127];
			float fTemp59 = fTemp58 - fVec2[(faust_wrap_sub(IOTA0, iConst118)) & 127];
			fVec52[0] = fTemp59;
			float fTemp60 = fTemp59 - fVec52[1];
			fVec53[0] = fTemp60;
			float fTemp61 = fTemp60 - fVec53[1];
			fVec54[0] = fTemp61;
			float fTemp62 = fTemp61 - fVec54[1];
			fVec55[0] = fTemp62;
			float fTemp63 = fTemp62 - fVec55[1];
			fVec56[0] = fTemp63;
			float fTemp64 = fTemp63 - fVec56[1];
			fVec57[0] = fTemp64;
			float fTemp65 = fTemp64 - fVec57[1];
			fVec58[0] = fTemp65;
			fRec0[0] = 0.0078125f * (fSlow13 * (fTemp58 - fConst133 * (fTemp59 + fConst132 * fTemp60 + fConst131 * fTemp61 + fConst130 * fTemp62 + fConst129 * fTemp63 + fConst128 * fTemp64 + fConst127 * fTemp65 + fConst126 * (fTemp65 - fVec58[1]))) + fSlow12 * (fTemp50 - fConst114 * (fTemp51 + fConst113 * fTemp52 + fConst112 * fTemp53 + fConst111 * fTemp54 + fConst110 * fTemp55 + fConst109 * fTemp56 + fConst108 * fTemp57 + fConst107 * (fTemp57 - fVec51[1]))) + fSlow11 * (fTemp42 - fConst95 * (fTemp43 + fConst94 * fTemp44 + fConst93 * fTemp45 + fConst92 * fTemp46 + fConst91 * fTemp47 + fConst90 * fTemp48 + fConst89 * fTemp49 + fConst88 * (fTemp49 - fVec44[1]))) + fSlow10 * (fTemp34 - fConst76 * (fTemp35 + fConst75 * fTemp36 + fConst74 * fTemp37 + fConst73 * fTemp38 + fConst72 * fTemp39 + fConst71 * fTemp40 + fConst70 * fTemp41 + fConst69 * (fTemp41 - fVec37[1]))) + fSlow9 * (fTemp26 - fConst57 * (fTemp27 + fConst56 * fTemp28 + fConst55 * fTemp29 + fConst54 * fTemp30 + fConst53 * fTemp31 + fConst52 * fTemp32 + fConst51 * fTemp33 + fConst50 * (fTemp33 - fVec30[1]))) + fSlow8 * (fTemp18 - fConst38 * (fTemp19 + fConst37 * fTemp20 + fConst36 * fTemp21 + fConst35 * fTemp22 + fConst34 * fTemp23 + fConst33 * fTemp24 + fConst32 * fTemp25 + fConst31 * (fTemp25 - fVec23[1]))) + fSlow7 * (fTemp10 - fConst19 * (fTemp11 + fConst18 * fTemp12 + fConst17 * fTemp13 + fConst16 * fTemp14 + fConst15 * fTemp15 + fConst14 * fTemp16 + fConst13 * fTemp17 + fConst12 * (fTemp17 - fVec16[1]))) + fSlow6 * (6.3441316e-18f * (fTemp9 - fVec9[1]) + 1.6917685e-17f * fTemp9 + 5.92119e-17f * fTemp8 + 3.5527137e-16f * fTemp7 + 4.0f * fTemp5 + fTemp2 + 4.0f * fTemp3 - (6.0f * fTemp4 + 1.0f * fTemp6)));
			float fTemp66 = std::min<float>(std::max<float>(fVec0[1] + fSlow4 * fRec1[1], -1.0f), 1.0f);
			fVec59[IOTA0 & 63] = fTemp66;
			fRec1[0] = 0.0078125f * (fSlow13 * fVec59[(faust_wrap_sub(IOTA0, iConst142)) & 63] + fSlow12 * fVec59[(faust_wrap_sub(IOTA0, iConst141)) & 63] + fSlow11 * fVec59[(faust_wrap_sub(IOTA0, iConst140)) & 63] + fSlow10 * fVec59[(faust_wrap_sub(IOTA0, iConst139)) & 63] + fSlow9 * fVec59[(faust_wrap_sub(IOTA0, iConst138)) & 63] + fSlow8 * fVec59[(faust_wrap_sub(IOTA0, iConst137)) & 63] + fSlow7 * fVec59[(faust_wrap_sub(IOTA0, iConst136)) & 63] + fSlow6 * fVec59[(faust_wrap_sub(IOTA0, iConst135)) & 63]);
			output0[i0] = static_cast<FAUSTFLOAT>(((iSlow0) ? fSlow18 * (fSlow17 * fTemp0 + fSlow15 * ((iSlow2) ? fRec1[1] : fRec0[1])) : fTemp0));
			float fTemp67 = static_cast<float>(input1[i0]);
			fVec60[0] = fTemp67;
			fVec61[IOTA0 & 65535] = std::min<float>(std::max<float>(fTemp67 + fSlow19 * fRec2[1], -1.0f), 1.0f);
			float fTemp68 = fVec61[(faust_wrap_sub(IOTA0, iSlow5)) & 65535];
			fVec62[IOTA0 & 127] = fTemp68;
			float fTemp69 = fVec62[(faust_wrap_sub(IOTA0, 28)) & 127];
			float fTemp70 = fVec62[(faust_wrap_sub(IOTA0, 29)) & 127] - fTemp69;
			fVec63[0] = fTemp70;
			float fTemp71 = fTemp70 - fVec63[1];
			fVec64[0] = fTemp71;
			float fTemp72 = fTemp71 - fVec64[1];
			fVec65[0] = fTemp72;
			float fTemp73 = fTemp72 - fVec65[1];
			fVec66[0] = fTemp73;
			float fTemp74 = fTemp73 - fVec66[1];
			fVec67[0] = fTemp74;
			float fTemp75 = fTemp74 - fVec67[1];
			fVec68[0] = fTemp75;
			float fTemp76 = fTemp75 - fVec68[1];
			fVec69[0] = fTemp76;
			float fTemp77 = fVec62[(faust_wrap_sub(IOTA0, iConst3)) & 127];
			float fTemp78 = fTemp77 - fVec62[(faust_wrap_sub(IOTA0, iConst4)) & 127];
			fVec70[0] = fTemp78;
			float fTemp79 = fTemp78 - fVec70[1];
			fVec71[0] = fTemp79;
			float fTemp80 = fTemp79 - fVec71[1];
			fVec72[0] = fTemp80;
			float fTemp81 = fTemp80 - fVec72[1];
			fVec73[0] = fTemp81;
			float fTemp82 = fTemp81 - fVec73[1];
			fVec74[0] = fTemp82;
			float fTemp83 = fTemp82 - fVec74[1];
			fVec75[0] = fTemp83;
			float fTemp84 = fTemp83 - fVec75[1];
			fVec76[0] = fTemp84;
			float fTemp85 = fVec62[(faust_wrap_sub(IOTA0, iConst22)) & 127];
			float fTemp86 = fTemp85 - fVec62[(faust_wrap_sub(IOTA0, iConst23)) & 127];
			fVec77[0] = fTemp86;
			float fTemp87 = fTemp86 - fVec77[1];
			fVec78[0] = fTemp87;
			float fTemp88 = fTemp87 - fVec78[1];
			fVec79[0] = fTemp88;
			float fTemp89 = fTemp88 - fVec79[1];
			fVec80[0] = fTemp89;
			float fTemp90 = fTemp89 - fVec80[1];
			fVec81[0] = fTemp90;
			float fTemp91 = fTemp90 - fVec81[1];
			fVec82[0] = fTemp91;
			float fTemp92 = fTemp91 - fVec82[1];
			fVec83[0] = fTemp92;
			float fTemp93 = fVec62[(faust_wrap_sub(IOTA0, iConst41)) & 127];
			float fTemp94 = fTemp93 - fVec62[(faust_wrap_sub(IOTA0, iConst42)) & 127];
			fVec84[0] = fTemp94;
			float fTemp95 = fTemp94 - fVec84[1];
			fVec85[0] = fTemp95;
			float fTemp96 = fTemp95 - fVec85[1];
			fVec86[0] = fTemp96;
			float fTemp97 = fTemp96 - fVec86[1];
			fVec87[0] = fTemp97;
			float fTemp98 = fTemp97 - fVec87[1];
			fVec88[0] = fTemp98;
			float fTemp99 = fTemp98 - fVec88[1];
			fVec89[0] = fTemp99;
			float fTemp100 = fTemp99 - fVec89[1];
			fVec90[0] = fTemp100;
			float fTemp101 = fVec62[(faust_wrap_sub(IOTA0, iConst60)) & 127];
			float fTemp102 = fTemp101 - fVec62[(faust_wrap_sub(IOTA0, iConst61)) & 127];
			fVec91[0] = fTemp102;
			float fTemp103 = fTemp102 - fVec91[1];
			fVec92[0] = fTemp103;
			float fTemp104 = fTemp103 - fVec92[1];
			fVec93[0] = fTemp104;
			float fTemp105 = fTemp104 - fVec93[1];
			fVec94[0] = fTemp105;
			float fTemp106 = fTemp105 - fVec94[1];
			fVec95[0] = fTemp106;
			float fTemp107 = fTemp106 - fVec95[1];
			fVec96[0] = fTemp107;
			float fTemp108 = fTemp107 - fVec96[1];
			fVec97[0] = fTemp108;
			float fTemp109 = fVec62[(faust_wrap_sub(IOTA0, iConst79)) & 127];
			float fTemp110 = fTemp109 - fVec62[(faust_wrap_sub(IOTA0, iConst80)) & 127];
			fVec98[0] = fTemp110;
			float fTemp111 = fTemp110 - fVec98[1];
			fVec99[0] = fTemp111;
			float fTemp112 = fTemp111 - fVec99[1];
			fVec100[0] = fTemp112;
			float fTemp113 = fTemp112 - fVec100[1];
			fVec101[0] = fTemp113;
			float fTemp114 = fTemp113 - fVec101[1];
			fVec102[0] = fTemp114;
			float fTemp115 = fTemp114 - fVec102[1];
			fVec103[0] = fTemp115;
			float fTemp116 = fTemp115 - fVec103[1];
			fVec104[0] = fTemp116;
			float fTemp117 = fVec62[(faust_wrap_sub(IOTA0, iConst98)) & 127];
			float fTemp118 = fTemp117 - fVec62[(faust_wrap_sub(IOTA0, iConst99)) & 127];
			fVec105[0] = fTemp118;
			float fTemp119 = fTemp118 - fVec105[1];
			fVec106[0] = fTemp119;
			float fTemp120 = fTemp119 - fVec106[1];
			fVec107[0] = fTemp120;
			float fTemp121 = fTemp120 - fVec107[1];
			fVec108[0] = fTemp121;
			float fTemp122 = fTemp121 - fVec108[1];
			fVec109[0] = fTemp122;
			float fTemp123 = fTemp122 - fVec109[1];
			fVec110[0] = fTemp123;
			float fTemp124 = fTemp123 - fVec110[1];
			fVec111[0] = fTemp124;
			float fTemp125 = fVec62[(faust_wrap_sub(IOTA0, iConst117)) & 127];
			float fTemp126 = fTemp125 - fVec62[(faust_wrap_sub(IOTA0, iConst118)) & 127];
			fVec112[0] = fTemp126;
			float fTemp127 = fTemp126 - fVec112[1];
			fVec113[0] = fTemp127;
			float fTemp128 = fTemp127 - fVec113[1];
			fVec114[0] = fTemp128;
			float fTemp129 = fTemp128 - fVec114[1];
			fVec115[0] = fTemp129;
			float fTemp130 = fTemp129 - fVec115[1];
			fVec116[0] = fTemp130;
			float fTemp131 = fTemp130 - fVec116[1];
			fVec117[0] = fTemp131;
			float fTemp132 = fTemp131 - fVec117[1];
			fVec118[0] = fTemp132;
			fRec2[0] = 0.0078125f * (fSlow13 * (fTemp125 - fConst133 * (fTemp126 + fConst132 * fTemp127 + fConst131 * fTemp128 + fConst130 * fTemp129 + fConst129 * fTemp130 + fConst128 * fTemp131 + fConst127 * fTemp132 + fConst126 * (fTemp132 - fVec118[1]))) + fSlow12 * (fTemp117 - fConst114 * (fTemp118 + fConst113 * fTemp119 + fConst112 * fTemp120 + fConst111 * fTemp121 + fConst110 * fTemp122 + fConst109 * fTemp123 + fConst108 * fTemp124 + fConst107 * (fTemp124 - fVec111[1]))) + fSlow11 * (fTemp109 - fConst95 * (fTemp110 + fConst94 * fTemp111 + fConst93 * fTemp112 + fConst92 * fTemp113 + fConst91 * fTemp114 + fConst90 * fTemp115 + fConst89 * fTemp116 + fConst88 * (fTemp116 - fVec104[1]))) + fSlow10 * (fTemp101 - fConst76 * (fTemp102 + fConst75 * fTemp103 + fConst74 * fTemp104 + fConst73 * fTemp105 + fConst72 * fTemp106 + fConst71 * fTemp107 + fConst70 * fTemp108 + fConst69 * (fTemp108 - fVec97[1]))) + fSlow9 * (fTemp93 - fConst57 * (fTemp94 + fConst56 * fTemp95 + fConst55 * fTemp96 + fConst54 * fTemp97 + fConst53 * fTemp98 + fConst52 * fTemp99 + fConst51 * fTemp100 + fConst50 * (fTemp100 - fVec90[1]))) + fSlow8 * (fTemp85 - fConst38 * (fTemp86 + fConst37 * fTemp87 + fConst36 * fTemp88 + fConst35 * fTemp89 + fConst34 * fTemp90 + fConst33 * fTemp91 + fConst32 * fTemp92 + fConst31 * (fTemp92 - fVec83[1]))) + fSlow7 * (fTemp77 - fConst19 * (fTemp78 + fConst18 * fTemp79 + fConst17 * fTemp80 + fConst16 * fTemp81 + fConst15 * fTemp82 + fConst14 * fTemp83 + fConst13 * fTemp84 + fConst12 * (fTemp84 - fVec76[1]))) + fSlow6 * (6.3441316e-18f * (fTemp76 - fVec69[1]) + 1.6917685e-17f * fTemp76 + 5.92119e-17f * fTemp75 + 3.5527137e-16f * fTemp74 + 4.0f * fTemp72 + fTemp69 + 4.0f * fTemp70 - (6.0f * fTemp71 + 1.0f * fTemp73)));
			float fTemp133 = std::min<float>(std::max<float>(fVec60[1] + fSlow19 * fRec3[1], -1.0f), 1.0f);
			fVec119[IOTA0 & 63] = fTemp133;
			fRec3[0] = 0.0078125f * (fSlow13 * fVec119[(faust_wrap_sub(IOTA0, iConst142)) & 63] + fSlow12 * fVec119[(faust_wrap_sub(IOTA0, iConst141)) & 63] + fSlow11 * fVec119[(faust_wrap_sub(IOTA0, iConst140)) & 63] + fSlow10 * fVec119[(faust_wrap_sub(IOTA0, iConst139)) & 63] + fSlow9 * fVec119[(faust_wrap_sub(IOTA0, iConst138)) & 63] + fSlow8 * fVec119[(faust_wrap_sub(IOTA0, iConst137)) & 63] + fSlow7 * fVec119[(faust_wrap_sub(IOTA0, iConst136)) & 63] + fSlow6 * fVec119[(faust_wrap_sub(IOTA0, iConst135)) & 63]);
			output1[i0] = static_cast<FAUSTFLOAT>(((iSlow0) ? fSlow18 * (fSlow16 * fTemp67 + fSlow14 * ((iSlow2) ? fRec3[1] : fRec2[1])) : fTemp67));
			fVec0[1] = fVec0[0];
			IOTA0 = faust_wrap_add(IOTA0, 1);
			fVec3[1] = fVec3[0];
			fVec4[1] = fVec4[0];
			fVec5[1] = fVec5[0];
			fVec6[1] = fVec6[0];
			fVec7[1] = fVec7[0];
			fVec8[1] = fVec8[0];
			fVec9[1] = fVec9[0];
			fVec10[1] = fVec10[0];
			fVec11[1] = fVec11[0];
			fVec12[1] = fVec12[0];
			fVec13[1] = fVec13[0];
			fVec14[1] = fVec14[0];
			fVec15[1] = fVec15[0];
			fVec16[1] = fVec16[0];
			fVec17[1] = fVec17[0];
			fVec18[1] = fVec18[0];
			fVec19[1] = fVec19[0];
			fVec20[1] = fVec20[0];
			fVec21[1] = fVec21[0];
			fVec22[1] = fVec22[0];
			fVec23[1] = fVec23[0];
			fVec24[1] = fVec24[0];
			fVec25[1] = fVec25[0];
			fVec26[1] = fVec26[0];
			fVec27[1] = fVec27[0];
			fVec28[1] = fVec28[0];
			fVec29[1] = fVec29[0];
			fVec30[1] = fVec30[0];
			fVec31[1] = fVec31[0];
			fVec32[1] = fVec32[0];
			fVec33[1] = fVec33[0];
			fVec34[1] = fVec34[0];
			fVec35[1] = fVec35[0];
			fVec36[1] = fVec36[0];
			fVec37[1] = fVec37[0];
			fVec38[1] = fVec38[0];
			fVec39[1] = fVec39[0];
			fVec40[1] = fVec40[0];
			fVec41[1] = fVec41[0];
			fVec42[1] = fVec42[0];
			fVec43[1] = fVec43[0];
			fVec44[1] = fVec44[0];
			fVec45[1] = fVec45[0];
			fVec46[1] = fVec46[0];
			fVec47[1] = fVec47[0];
			fVec48[1] = fVec48[0];
			fVec49[1] = fVec49[0];
			fVec50[1] = fVec50[0];
			fVec51[1] = fVec51[0];
			fVec52[1] = fVec52[0];
			fVec53[1] = fVec53[0];
			fVec54[1] = fVec54[0];
			fVec55[1] = fVec55[0];
			fVec56[1] = fVec56[0];
			fVec57[1] = fVec57[0];
			fVec58[1] = fVec58[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fVec60[1] = fVec60[0];
			fVec63[1] = fVec63[0];
			fVec64[1] = fVec64[0];
			fVec65[1] = fVec65[0];
			fVec66[1] = fVec66[0];
			fVec67[1] = fVec67[0];
			fVec68[1] = fVec68[0];
			fVec69[1] = fVec69[0];
			fVec70[1] = fVec70[0];
			fVec71[1] = fVec71[0];
			fVec72[1] = fVec72[0];
			fVec73[1] = fVec73[0];
			fVec74[1] = fVec74[0];
			fVec75[1] = fVec75[0];
			fVec76[1] = fVec76[0];
			fVec77[1] = fVec77[0];
			fVec78[1] = fVec78[0];
			fVec79[1] = fVec79[0];
			fVec80[1] = fVec80[0];
			fVec81[1] = fVec81[0];
			fVec82[1] = fVec82[0];
			fVec83[1] = fVec83[0];
			fVec84[1] = fVec84[0];
			fVec85[1] = fVec85[0];
			fVec86[1] = fVec86[0];
			fVec87[1] = fVec87[0];
			fVec88[1] = fVec88[0];
			fVec89[1] = fVec89[0];
			fVec90[1] = fVec90[0];
			fVec91[1] = fVec91[0];
			fVec92[1] = fVec92[0];
			fVec93[1] = fVec93[0];
			fVec94[1] = fVec94[0];
			fVec95[1] = fVec95[0];
			fVec96[1] = fVec96[0];
			fVec97[1] = fVec97[0];
			fVec98[1] = fVec98[0];
			fVec99[1] = fVec99[0];
			fVec100[1] = fVec100[0];
			fVec101[1] = fVec101[0];
			fVec102[1] = fVec102[0];
			fVec103[1] = fVec103[0];
			fVec104[1] = fVec104[0];
			fVec105[1] = fVec105[0];
			fVec106[1] = fVec106[0];
			fVec107[1] = fVec107[0];
			fVec108[1] = fVec108[0];
			fVec109[1] = fVec109[0];
			fVec110[1] = fVec110[0];
			fVec111[1] = fVec111[0];
			fVec112[1] = fVec112[0];
			fVec113[1] = fVec113[0];
			fVec114[1] = fVec114[0];
			fVec115[1] = fVec115[0];
			fVec116[1] = fVec116[0];
			fVec117[1] = fVec117[0];
			fVec118[1] = fVec118[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
