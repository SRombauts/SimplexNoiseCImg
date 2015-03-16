
/// Pimpl of CImg to reduce compile time
class ImgImpl;

/// Encapsulation of CImg to reduce compile time
class Img {
public:
    Img();

    bool is_closed() const;

    void set_title(const char* title);
    void draw_point(int col, int row, float* color);
    void display();

    void user(float& scale, float& offset_x, float& offset_y, float& offset_z, float& lacunarity, float& persistance);

    int height() const;
    int width() const;

private:
    ImgImpl& mImgImpl;
};
