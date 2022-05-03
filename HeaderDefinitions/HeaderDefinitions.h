#pragma once
/**
*
* @Author: Billy Ndegwah Micah [ billyndegz13@gmail.com ]
*
*/


#ifndef HEADERDEFS

struct FrameErrorCheck{
	int parityCheck;
	int checkSum;
	int cyclicRedundacyCheck;

	int setFCSValue(int dataStream, char* method) {
		int value;

		if (method == "parity") {
			value = computeParityCheck(dataStream);
		} 
		else if (method == "checksum") {
			value = computeChecksum(dataStream);
		}
		else if (method == "crc") {
			value = computeCRC(dataStream);
		}

		frameCheckSequence = value;
		return value;
	}

	int getFCSValue() {
		return frameCheckSequence;
	}

private:
	/** 
	* The frame check sequence contains the logical value(Cyclic Redundacy Check - CRC)
	* created by the senders checksum, it is attached as FCS in the trailer as a means for reference
	* in order that the receiver can check the received frame's checksum against
	* the value in the FCS to ascertain that they match which would be the confirmation
	* that there aren't any errors in the frame.
	*/
	int frameCheckSequence;

	/**
	* Reference for error calculation methods: 
	*			https://www.tutorialspoint.com/error-detection-and-correction-in-data-link-layer
	* 
	* PARITY CHECK METHOD
	* -------------------
	* 
	* The parity check is done by adding an extra bit, called parity bit to the data to make a 
	* number of 1s either even in case of even parity or odd in case of odd parity. 
	* While creating a frame, the sender counts the number of 1s in it and adds the parity 
	* bit in the following way
	* In case of even parity: If a number of 1s is even then parity bit value is 0. 
	* If the number of 1s is odd then parity bit value is 1.
	* In case of odd parity: If a number of 1s is odd then parity bit value is 0. 
	* If a number of 1s is even then parity bit value is 1.
	* On receiving a frame, the receiver counts the number of 1s in it. 
	* In case of even parity check, if the count of 1s is even, the frame is accepted, 
	* otherwise, it is rejected. A similar rule is adopted for odd parity check.
	* The parity check is suitable for single bit error detection only.
	* 
	* CHECKSUM METHOD
	* ---------------
	* 
	* In this error detection scheme, the following procedure is applied
	* Data is divided into fixed sized frames or segments.
	* The sender adds the segments using 1’s complement arithmetic to get the sum.
	* It then complements the sum to get the checksum and sends it along with the data frames.
	* The receiver adds the incoming segments along with the checksum using 1’s complement 
	* arithmetic to get the sum and then complements it.
	* If the result is zero, the received frames are accepted; otherwise, they are discarded. 
	* 
	* CRC METHOD
	* ----------
	* 
	* Cyclic Redundancy Check (CRC) involves binary division of the data bits
	* being sent by a predetermined divisor agreed upon by the communicating system. 
	* The divisor is generated using polynomials.
	* Here, the sender performs binary division of the data segment by the divisor.
	* It then appends the remainder called CRC bits to the end of the data segment.
	* This makes the resulting data unit exactly divisible by the divisor.
	* The receiver divides the incoming data unit by the divisor. If there is no remainder, 
	* the data unit is assumed to be correct and is accepted. Otherwise, it is understood 
	* that the data is corrupted and is therefore rejected.
	* 
	* I'll implement an overly simplified check method for now
	*/
	
	int computeParityCheck(int value) {
		return value / 45;
	}

	int computeChecksum(int value) {
		return value / -26;
	}

	int computeCRC(int value) {
		return value % 3;
	}
};

#endif // !HEADERDEFS

