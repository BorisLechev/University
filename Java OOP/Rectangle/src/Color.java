public class Color implements Comparable {
    final static int RED_BASE = 256 * 256;
    final static int GREEN_BASE = 256;
    final static int BLUE_BASE = 1;
    final static long RED_MASK = 0x00ffff;
    final static long GREEN_MASK = 0xff00ff;
    final static long BLUE_MASK = 0xffff00;

    final static int BYTE_MASK = 255;
    private long red;
    private long green;
    private long blue;
    protected long color;

    public long getRed() {
        return red;
    }

    public void setRed(long r) {
        red = r;
        color = (color & RED_MASK) | (r << 16);
    }

    public long getGreen() {
        return green;
    }

    public void setGreen(long g) {
        green = g;
        color = (color & GREEN_MASK) | (g << 8);
    }

    public long getBlue() {
        return blue;
    }

    public void setBlue(long b) {
        blue = b;
        color = (color & BLUE_MASK) | b;
    }

    public long getColor() {
        return color;
    }

    public void setColor(long c) {
        color = c;
        color2RGB();
    }

    public Color() {
        red = Console.readLong("Enter an Red part: ");
        green = Console.readLong("Enter an Green part: ");
        blue = Console.readLong("Enter an Blue part: ");
        rgb2color();
    }


    public Color(long r, long g, long b) {
        red = r;
        green = g;
        blue = b;
        rgb2color();
    }

    private void rgb2color() {
        color = red * RED_BASE + green * GREEN_BASE + blue;
    }

    private void color2RGB() {
        red = color >>> 16;
        green = (color >>> 8) & BYTE_MASK;
        blue = color & BYTE_MASK;
    }

    // Eксплицитен констуктор
    public Color(long c) {
        color = c;
        color2RGB();
    }

    public String toString() {
        return "Red: " + red + " Green: " + green + " Blue: " + blue + " Compound: " + color;
    }

    public boolean equals(Object c) {
        return color == ((Color) c).color;
    }

    public int compareTo(Object c) {
        if (this.color < ((Color) c).color) return -1;
        if (this.color > ((Color) c).color) return 1;
        return 0;
    }

    public static void main(String[] args) {
        Color blue = new Color(BLUE_BASE * 255);
        Color green = new Color(GREEN_BASE * 255);
        Color red = new Color(RED_BASE * 255);

        System.out.println(blue.toString());
        System.out.println(green.toString());
        System.out.println(red.toString());
        System.out.println("Default test : " + new Color());
    }
}
