struct PixelShaderOutput
{
    float4 color : SV_TARGET0;
};

Const 

struct PixelShaderOutput
{
    float color : SV_TARGET0;
};

PixelShaderOutput main()
{
    PixelShaderOutput output;
    output.color = float4(1, 1, 1, 1);
    return output;
}