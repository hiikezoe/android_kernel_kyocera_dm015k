/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
/*
 * This software is contributed or developed by KYOCERA Corporation.
 * (C) 2012 KYOCERA Corporation
 * (C) 2013 KYOCERA Corporation
 */

#include <linux/mfd/pm8xxx/batterydata-lib.h>

#ifdef QUALCOMM_ORIGINAL_FEATURE
static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 65},
	.y		= {1492, 1492, 1493, 1483, 1502},
	.cols	= 5
};
#else
static struct single_row_lut fcc_temp = {
	.x	= {-20, -10, 0, 10, 20, 35, 45, 60},
	.y	= {955, 1417, 1590, 1628, 1697, 1710, 1710, 1710},
	.cols	= 8,
};
#endif

static struct single_row_lut palladium_1500_fcc_sf = {
	.x	= {0, 100, 250, 450, 650, 850},
	.y	= {100, 93, 85, 78, 71, 56},
	.cols	= 6,
};

static struct sf_lut palladium_1500_pc_sf = {
	.rows		= 10,
	.cols		= 6,
	/* row_entries are chargecycles */
	.row_entries	= {0, 100, 250, 450, 650, 850},
	.percent	= {100, 90, 80, 70, 60, 50, 40, 30, 20, 10},
	.sf		= {
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56},
			{100 ,93 ,85 ,78 ,71 ,56}
	},
};

#ifdef QUALCOMM_ORIGINAL_FEATURE
static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.ocv		= {
				{4173, 4167, 4163, 4156, 4154},
				{4104, 4107, 4108, 4102, 4104},
				{4057, 4072, 4069, 4061, 4060},
				{3973, 4009, 4019, 4016, 4020},
				{3932, 3959, 3981, 3982, 3983},
				{3899, 3928, 3954, 3950, 3950},
				{3868, 3895, 3925, 3921, 3920},
				{3837, 3866, 3898, 3894, 3892},
				{3812, 3841, 3853, 3856, 3862},
				{3794, 3818, 3825, 3823, 3822},
				{3780, 3799, 3804, 3804, 3803},
				{3768, 3787, 3790, 3788, 3788},
				{3757, 3779, 3778, 3775, 3776},
				{3747, 3772, 3771, 3766, 3765},
				{3736, 3763, 3766, 3760, 3746},
				{3725, 3749, 3756, 3747, 3729},
				{3714, 3718, 3734, 3724, 3706},
				{3701, 3703, 3696, 3689, 3668},
				{3675, 3695, 3682, 3675, 3662},
				{3670, 3691, 3680, 3673, 3661},
				{3661, 3686, 3679, 3672, 3656},
				{3649, 3680, 3676, 3669, 3641},
				{3633, 3669, 3667, 3655, 3606},
				{3610, 3647, 3640, 3620, 3560},
				{3580, 3607, 3596, 3572, 3501},
				{3533, 3548, 3537, 3512, 3425},
				{3457, 3468, 3459, 3429, 3324},
				{3328, 3348, 3340, 3297, 3172},
				{3000, 3000, 3000, 3000, 3000}
	}
};
#else
static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 8,
	.temp		= {-20, -10, 0, 10, 20, 35, 45, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55,
				50, 45, 40, 35, 30, 25, 20, 15, 10, 9,
				8, 7, 6, 5, 4, 3, 2, 1, 0
	},
	.ocv		= {
			{4061, 4144, 4190, 4213, 4245, 4255, 4255, 4255},
			{3843, 4028, 4107, 4138, 4180, 4195, 4195, 4195},
			{3779, 3972, 4053, 4087, 4128, 4143, 4143, 4143},
			{3728, 3921, 4005, 4040, 4078, 4093, 4093, 4093},
			{3686, 3868, 3953, 3992, 4031, 4045, 4045, 4045},
			{3649, 3825, 3905, 3944, 3983, 3999, 3999, 3999},
			{3617, 3788, 3867, 3903, 3938, 3955, 3955, 3955},
			{3587, 3752, 3831, 3864, 3893, 3909, 3909, 3909},
			{3561, 3720, 3798, 3832, 3857, 3868, 3868, 3868},
			{3536, 3691, 3771, 3805, 3828, 3839, 3839, 3839},
			{3510, 3665, 3747, 3783, 3804, 3814, 3814, 3814},
			{3489, 3644, 3726, 3763, 3783, 3793, 3793, 3793},
			{3468, 3624, 3709, 3746, 3765, 3775, 3775, 3775},
			{3448, 3604, 3694, 3731, 3748, 3758, 3758, 3758},
			{3428, 3581, 3679, 3717, 3733, 3738, 3738, 3738},
			{3408, 3554, 3660, 3703, 3717, 3717, 3717, 3717},
			{3388, 3522, 3634, 3682, 3699, 3700, 3700, 3700},
			{3367, 3484, 3601, 3655, 3675, 3676, 3676, 3676},
			{3344, 3438, 3558, 3628, 3651, 3655, 3655, 3655},
			{3341, 3427, 3546, 3622, 3647, 3653, 3653, 3653},
			{3336, 3416, 3533, 3615, 3643, 3650, 3650, 3650},
			{3331, 3404, 3518, 3605, 3636, 3645, 3645, 3645},
			{3327, 3392, 3501, 3591, 3626, 3635, 3635, 3635},
			{3323, 3379, 3480, 3570, 3606, 3612, 3612, 3612},
			{3318, 3366, 3455, 3542, 3571, 3577, 3577, 3577},
			{3314, 3351, 3426, 3505, 3528, 3532, 3532, 3532},
			{3311, 3335, 3392, 3454, 3472, 3474, 3474, 3474},
			{3305, 3319, 3351, 3390, 3404, 3409, 3409, 3409},
			{3300, 3300, 3300, 3300, 3300, 3300, 3300, 3300}
	},
};
#endif

static struct rbatt_lut oem_rbatt_initial = {
	.rows	= 22,
	.cols	= 5,
	.temp	= {-20, 0, 25, 40, 65},
	.vbatt	= {4350, 4300, 4250, 4200, 4150, 4100, 4050, 4000,
		   3950, 3900, 3850, 3800, 3750, 3700, 3650, 3600,
		   3550, 3500, 3450, 3400, 3350, 3300
	},
	.rbatt	= {
				{1335, 498, 160, 143, 140},
				{1335, 498, 160, 143, 140},
				{1335, 495, 160, 143, 135},
				{1335, 480, 160, 143, 140},
				{1335, 478, 160, 143, 138},
				{1330, 463, 163, 143, 138},
				{1320, 463, 160, 143, 140},
				{1305, 460, 163, 143, 140},
				{1298, 460, 160, 145, 140},
				{1288, 460, 160, 145, 140},
				{1280, 465, 163, 143, 140},
				{1280, 470, 163, 143, 140},
				{1283, 483, 165, 145, 140},
				{1285, 500, 168, 145, 140},
				{1290, 510, 168, 145, 140},
				{1295, 525, 170, 145, 143},
				{1305, 550, 173, 148, 143},
				{1325, 603, 173, 148, 145},
				{1338, 650, 175, 150, 145},
				{1348, 683, 175, 150, 145},
				{1350, 693, 178, 153, 145},
				{1350, 698, 190, 153, 150}
	}
};

static struct soc_adjust_lut oem_soc_adjust = {
	.rows		= 6,
	.cols		= 8,
	.temp		= {-30, -20, -10, 0, 10, 25, 40, 60},
	.ibatt		= {1000, 800, 600, 400, 200, 100},
	.soc_adjust	= {
				{15, 10,  6,  0,  0,  0,  0,  0},
				{17, 11,  7,  0,  0,  0,  0,  0},
				{20, 12,  8,  0,  0,  0,  0,  0},
				{23, 13,  9,  1,  0,  0,  0,  0},
				{27, 14, 10,  1,  0,  0,  0,  0},
				{33, 15, 11,  2,  0,  0,  0,  0}
	}
};

static struct single_row_lut oem_cycle_adjust = {
	.x	= {185, 222, 259, 296, 333, 407},
	.y	= {0, 100, 250, 400, 650, 850},
	.cols	= 6,
};

#ifdef QUALCOMM_ORIGINAL_FEATURE
static struct sf_lut rbatt_sf = {
	.rows		= 29,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 20, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.sf		= {
				{357, 187, 100, 91, 91},
				{400, 208, 105, 94, 94},
				{390, 204, 106, 95, 96},
				{391, 201, 108, 98, 98},
				{391, 202, 110, 98, 100},
				{390, 200, 110, 99, 102},
				{389, 200, 110, 99, 102},
				{393, 202, 101, 93, 100},
				{407, 205, 99, 89, 94},
				{428, 208, 100, 91, 96},
				{455, 212, 102, 92, 98},
				{495, 220, 104, 93, 101},
				{561, 232, 107, 95, 102},
				{634, 245, 112, 98, 98},
				{714, 258, 114, 98, 98},
				{791, 266, 114, 97, 100},
				{871, 289, 108, 95, 97},
				{973, 340, 124, 108, 105},
				{489, 241, 109, 96, 99},
				{511, 246, 110, 96, 99},
				{534, 252, 111, 95, 98},
				{579, 263, 112, 96, 96},
				{636, 276, 111, 95, 97},
				{730, 294, 109, 96, 99},
				{868, 328, 112, 98, 104},
				{1089, 374, 119, 101, 115},
				{1559, 457, 128, 105, 213},
				{12886, 1026, 637, 422, 3269},
				{170899, 127211, 98968, 88907, 77102},
	}
};
#else
static struct sf_lut rbatt_sf = {
	.rows		= 29,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.sf		= {
				{788, 246, 100, 88, 84},
				{790, 247, 102, 88, 84},
				{788, 246, 100, 88, 85},
				{789, 246, 100, 88, 86},
				{790, 248, 100, 88, 84},
				{793, 250, 102, 89, 85},
				{797, 252, 102, 89, 86},
				{800, 256, 101, 88, 86},
				{802, 256, 102, 89, 85},
				{804, 259, 102, 88, 86},
				{808, 266, 102, 89, 88},
				{809, 270, 103, 89, 85},
				{811, 279, 104, 90, 87},
				{813, 292, 106, 90, 84},
				{812, 305, 106, 90, 85},
				{814, 319, 108, 88, 88},
				{814, 342, 110, 90, 86},
				{815, 369, 111, 90, 85},
				{815, 392, 112, 92, 88},
				{816, 396, 112, 91, 87},
				{817, 399, 114, 92, 88},
				{816, 401, 115, 93, 88},
				{818, 403, 115, 93, 88},
				{816, 406, 117, 93, 88},
				{816, 408, 119, 93, 89},
				{820, 411, 123, 94, 88},
				{818, 414, 124, 96, 90},
				{818, 419, 130, 97, 92},
				{819, 423, 124, 99, 90},
	}
};
#endif

#ifdef QUALCOMM_ORIGINAL_FEATURE
struct bms_battery_data palladium_1500_data = {
	.fcc			= 1500,
	.fcc_temp_lut		= &fcc_temp,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm	= 236,
	.rbatt_capacitive_mohm	= 50,
};
#else
struct bms_battery_data palladium_1500_data = {
	.fcc			= 1750,
	.fcc_temp_lut		= &fcc_temp,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm	= 185,
	.fcc_sf_lut		= &palladium_1500_fcc_sf,
	.pc_sf_lut		= &palladium_1500_pc_sf,
	.delta_rbatt_mohm	= 60,
};
#endif

struct pm8921_bms_oem_battery_data pm8921_bms_oem_data = {
	.rbatt_initial_lut	= &oem_rbatt_initial,
	.soc_adjust_lut		= &oem_soc_adjust,
	.cycle_adjust_lut	= &oem_cycle_adjust,
};
