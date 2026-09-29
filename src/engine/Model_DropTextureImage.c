/* Drops a model's texture image from main memory: the archive block of the model's resource
 * (+0x74) is shrunk to end where its texture image starts (ModelArchive_DropTextureImage). */

extern int ModelArchive_DropTextureImage();

int Model_DropTextureImage(int model) {
    int p = *(int *)(model + 0x74);
    return ModelArchive_DropTextureImage(*(int *)(p + 0xc), *(int *)(p + 8), *(unsigned short *)(p + 6));
}
