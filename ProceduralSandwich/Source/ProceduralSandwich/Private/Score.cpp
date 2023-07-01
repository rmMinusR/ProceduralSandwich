// Fill out your copyright notice in the Description page of Project Settings.


#include "Score.h"

FScore::FScore()
{
	// Set defaults for CDO
	annoyance = 0;
	promotion = 0;
}

FScore::~FScore()
{
}

FScore FScore::operator+(const FScore& rhs) const
{
	FScore out;
	out.annoyance = this->annoyance + rhs.annoyance;
	out.promotion = this->promotion + rhs.promotion;
	return out;
}

FScore& FScore::operator+=(const FScore& rhs)
{
	annoyance += rhs.annoyance;
	promotion += rhs.promotion;
	return *this;
}
