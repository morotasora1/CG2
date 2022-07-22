#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);
SamplerState smp : register(s0);

cbuffer ConstBufferDataMaterial : register(b0)
{
	float4 color;
};

float4 main(VSOutput input) : SV_TARGET
{

	return float4(tex.Sample(smp,input.uv)) * color;
	//return color;
}