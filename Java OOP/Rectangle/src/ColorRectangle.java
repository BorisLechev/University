public class ColorRectangle extends Color implements Comparable {
    private int iX1;
    private int iY1;
    private int iX2;
    private int iY2;

    public ColorRectangle() {
        super(255);
        iX1 = -1;
        iY1 = -1;
        iX2 = -1;
        iY2 = -1;
    }

    public ColorRectangle(int x1, int y1, int x2, int y2) {
        super(255);
        iX1 = x1;
        iY1 = y1;
        iX2 = x2;
        iY2 = y2;
    }

    public ColorRectangle(int x1, int y1, int x2, int y2, long c) {
        super(c);
        iX1 = x1;
        iY1 = y1;
        iX2 = x2;
        iY2 = y2;
    }

    public int getIX1() {
        return iX1;
    }

    public void setIX1(int x1) {
        iX1 = x1;
    }

    public int getIX2() {
        return iX2;
    }

    public void setIX2(int x2) {
        iX2 = x2;
    }

    public int getIY1() {
        return iY1;
    }

    public void setIY1(int y1) {
        iY1 = y1;
    }

    public int getIY2() {
        return iY2;
    }

    public void setIY2(int y2) {
        iY2 = y2;
    }

    public int area() {
        return Math.abs((iX2 - iX1) * (iY2 - iY1));
    }

    public int perimeter() {
        return 2 * (Math.abs((iX2 - iX1)) + Math.abs((iY2 - iY1)));
    }

    public int compareTo(Object r) {
        if (this.area() < ((ColorRectangle) r).area()) return -1;
        if (this.area() > ((ColorRectangle) r).area()) return 1;
        return 0;
    }

    public String toString() {
        return "iX1: " + iX1 + " iY1: " + iY1 + " | iX2: " + iX2 + " iY2: " + iY2 + " | " + super.toString();
    }

    public boolean equals(ColorRectangle r) {
        if (this.area() == r.area() && (super.getColor() == getColor())) {
            return true;
        }
        return false;
    }

    public void translateX(int iPoints) {
        iX1 += iPoints;
        iX2 += iPoints;
    }

    public void translateY(int iPoints) {
        iY1 += iPoints;
        iY2 += iPoints;
    }

    public boolean isInside(int x, int y) {
        return ((x >= iX1) && (x <= iX2) && (y >= iY1) && (y <= iY2));
    }

    public ColorRectangle unionRect(ColorRectangle r) {
        return new ColorRectangle((this.iX1 < r.iX1) ? this.iX1 : r.iX1,
                (this.iY1 < r.iY1) ? this.iY1 : r.iY1,
                (this.iX2 > r.iX2) ? this.iX2 : r.iX2,
                (this.iY2 > r.iY2) ? this.iY2 : r.iY2, r.getColor() + this.getColor());
    }

    public ColorRectangle intersectionRect(ColorRectangle r) {
        ColorRectangle result = new ColorRectangle(
                (this.iX1 > r.iX1) ? this.iX1 : r.iX1,
                (this.iY1 > r.iY1) ? this.iY1 : r.iY1,
                (this.iX2 < r.iX2) ? this.iX2 : r.iX2,
                (this.iY2 < r.iY2) ? this.iY2 : r.iY2, r.getColor() + this.getColor());

        if (result.iX1 > result.iX2) {
            result.iX1 = result.iX2 = 0;
        }

        if (result.iY1 > result.iY2) {
            result.iY1 = result.iY2 = 0;
        }
        return result;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
		/*
		int x1 = Console.readInt("Enter an X1: ");
		int y1 = Console.readInt("Enter an Y1: ");
		int x2 = Console.readInt("Enter an X2: ");
		int y2 = Console.readInt("Enter an Y2: ");
		long lColor=Console.readLong("Enter an color : ");
		ColorRectangle oRect = new ColorRectangle(x1,y1,x2,y2,lColor);
		*/
        ColorRectangle oRect = new ColorRectangle();
        System.out.println(oRect.toString());
        oRect.translateX(Console.readInt("point to translate by X: "));
        System.out.println(oRect.toString());
        oRect.translateY(Console.readInt("point to translate by Y: "));
        System.out.println(oRect.toString());
		/*
		int x1 = Console.readInt("Enter an X1: ");
		int y1 = Console.readInt("Enter an Y1: ");
		int x2 = Console.readInt("Enter an X2: ");
		int y2 = Console.readInt("Enter an Y2: ");
		long lColor=Console.readLong("Enter an color : ");
		ColorRectangle oRect2=new ColorRectangle(x1,y1,x2,y2,lColor);
		*/
        ColorRectangle oRect2 = new ColorRectangle();
        System.out.println(oRect2.toString());

        if (oRect.equals(oRect2)) {
            System.out.println("equal OK");
        } else {
            System.out.println("equal FALSE");
        }

        ColorRectangle resUnion = oRect.unionRect(oRect2);
        System.out.println("Union:" + resUnion.toString() + " area:" + resUnion.area());
        ColorRectangle resInters = oRect.intersectionRect(oRect2);
        System.out.println("Inters:" + resInters.toString() + " area:" + resInters.area());
    }
}