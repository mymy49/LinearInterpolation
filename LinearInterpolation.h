/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_MODULE_LINEAR_INTERPOLATION__H_
#define	YSS_MODULE_LINEAR_INTERPOLATION__H_

/**
 * @class LinearInterpolation
 * @brief A class that implements linear interpolation (LERP) to map and calculate values between two data points.
 * @details This class takes two reference points (P1 and P2) consisting of input values (e.g., ADC raw data) 
 *          and target output values, then computes an interpolated output for any given input value within or near the range.
 * 
 * @author Yoon-Ki Hong
 * @date 2026. 06. 01. (Or your original creation date)
 * @version 1.0.0
 */
class LinearInterpolation
{
public :
	/**
	 * @brief Constructor with initial target values for P1 and P2.
	 * @param valueP1 Target output value for Point 1
	 * @param valueP2 Target output value for Point 2
	 */
	LinearInterpolation(float valueP1, float ValueP2);

	/**
	 * @brief Default constructor.
	 */
	LinearInterpolation(void);

	/**
	 * @brief Set the target output value for Point 1.
	 * @param value Target output value
	 */
	void setValueP1(float value);

	/**
	 * @brief Set the target output value for Point 2.
	 * @param value Target output value
	 */
	void setValueP2(float value);

	/**
	 * @brief Set the input value (e.g., ADC raw data) for Point 1.
	 * @param val Input reference value
	 */
	void setAdcP1(float val);

	/**
	 * @brief Set the input value (e.g., ADC raw data) for Point 2.
	 * @param val Input reference value
	 */
	void setAdcP2(float val);

	/**
	 * @brief Calculate the linear interpolated value based on the given input.
	 * @param adc The current input value to be mapped
	 * @return float The calculated/interpolated target value
	 */
	float calculate(float adc);

private :
	float mAdcP1;        ///< Input reference value for Point 1
	float mAdcP2;        ///< Input reference value for Point 2
	float mValueP1;      ///< Target output value for Point 1
	float mValueP2;      ///< Target output value for Point 2
	float mAdcOffset;    ///< Difference between mAdcP2 and mAdcP1 (mAdcP2 - mAdcP1)
	float mValueOffset;  ///< Difference between mValueP2 and mValueP1 (mValueP2 - mValueP1)
};

#endif