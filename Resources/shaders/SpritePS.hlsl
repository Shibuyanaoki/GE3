struct PixelShaderOutput
{
    float4 color : SV_TARGETO;
};

PixelShaderOutput main()
{
    PixelShaderOutput output;
    output.color = float(1, 1, 1, 1);
    return output;
}