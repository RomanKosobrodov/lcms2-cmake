#include <lcms2.h>
#include <cstdint>

int main(int argc, char *argv[])
{
    cmsHPROFILE srgb_profile = cmsCreate_sRGBProfile();
    cmsHPROFILE xyz_profile = cmsCreateXYZProfile();
    cmsHTRANSFORM transform;

    transform = cmsCreateTransform(srgb_profile,
                                   TYPE_RGB_DBL,
                                   xyz_profile,
                                   TYPE_XYZ_DBL,
                                   INTENT_PERCEPTUAL, 0);
    cmsCloseProfile(srgb_profile);
    cmsCloseProfile(xyz_profile);

    double rbg_buffer[] = {0.112, 0.45, 0.87};
    double xyz_buffer[3];
    const uint32_t size = 1;

    cmsDoTransform(transform,
                   rbg_buffer,
                   xyz_buffer,
                   size);

    cmsDeleteTransform(transform);

    return 0;
}