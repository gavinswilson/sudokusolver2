import numpy as np

class sudoku_grid:
    null_value=99

    def __init__(self, row, col, numsize_min, numsize_max) -> None:
        self.rows = row
        self.cols = col
        self.options_max = numsize_max
        self.options_min = numsize_min
        self.grid = np.zeros((self.rows, self.cols), dtype=np.uint16)
        self.clear_grid(self.null_value)
        self.opts = np.zeros((self.rows, self.cols), dtype=np.uint16)
        self.set_all_opts()
        self.regions = np.zeros((self.rows, self.cols), dtype=int)
        self.set_region_map()
        self.set_regions()
        self.mask=np.uint16(np.left_shift(np.uint16(65535),np.uint16(self.get_opts_max()-self.get_opts_min()+1)))

    from ._sgrid_gets import get_rows
    from ._sgrid_gets import get_cols
    from ._sgrid_gets import get_opts
    from ._sgrid_gets import get_value
    from ._sgrid_gets import get_region
    from ._sgrid_gets import get_opts_min
    from ._sgrid_gets import get_opts_max
    from ._sgrid_gets import get_mask
    
    from ._sgrid_sets import set_value
    from ._sgrid_sets import set_opts
    from ._sgrid_sets import set_all_opts
    from ._sgrid_sets import clear_grid
    from ._sgrid_sets import set_region_map
    from ._sgrid_sets import set_regions
    from ._sgrid_sets import set_region
    
    from ._sgrid_solver import remove_knowns
    from ._sgrid_solver import remove_knows_from_cell_opts

    from ._sgrid_bin_funcs import all_options_number_bin
    from ._sgrid_bin_funcs import get_mask_for_option

    from ._sgrid_print import print_grid
    from ._sgrid_print import print_opts
    from ._sgrid_print import print_regions

