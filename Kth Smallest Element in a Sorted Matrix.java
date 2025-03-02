class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int[] array = new int[matrix.length * matrix[0].length];
        int l = 0;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                array[l] = matrix[i][j];
                l++;
            }
        }

        Arrays.sort(array);

        for (int i = 0; i < array.length; i++) {
            if (i == k - 1) {
                return array[i];
            }
        }

        return 1;
    }
}