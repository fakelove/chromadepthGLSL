uniform sampler2DRect diffusemap;
varying float depth;
varying float lighting;
varying float specular;

void main (void)
{
    vec4 rgb = vec4(0.0, 0.0, 0.0, 1.0);
    /* these formulas are based on code from American Paper Optics at:
       http://www.chromatek.com/Image_Design/Color_Lookup_Functions/color_lookup_functions.shtml */
    float depth2 = depth*depth;
    if (depth < 0.5) {
        rgb.y = 1.6*depth2+1.2*depth;
    } else {
        rgb.y = 3.2*depth2-6.8*depth+3.6;
        rgb.z = depth2*-4.8+9.2*depth-3.4;
    }
    float tdepth = depth/0.9;
    depth2 = depth2/0.81;
    rgb.r = -2.14*depth2*depth2 -1.07*depth2*depth + 0.133*depth2 +0.0667*tdepth +1.0;

    vec3 texval = texture2DRect(diffusemap,gl_TexCoord[0].st).xyz/2.0 + 0.5;
    
    gl_FragColor = rgb*vec4(texval, 1.0);
}
