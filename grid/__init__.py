import numpy as np

class sudoku_grid:
    null_value=99
    debug=3

    def __init__(self, row, col, numsize_min, numsize_max) -> None:
        if self.debug>=1: print("Entering __init()__")
        self.rows = row
        if self.debug>=2: print("Rows:", self.rows)
        self.cols = col
        if self.debug>=2: print("cols:", self.cols)
        self.options_max = numsize_max
        if self.debug>=2: print("Opt-Max:", self.options_max)
        self.options_min = numsize_min
        if self.debug>=2: print("Opt-Min:", self.options_min)
        self.grid = np.zeros((self.rows, self.cols), dtype=np.uint16)
        if self.debug>=1: print("Creating grid")
        if self.debug>=3: print(self.grid)
        self.clear_grid(self.null_value)
        if self.debug>=2: print("Clearing grid to null - null Val:", self.null_value)
        if self.debug>=3: print(self.grid)
        self.opts = np.zeros((self.rows, self.cols), dtype=np.uint16)
        if self.debug>=1: print("Creating opts")
        if self.debug>=3: print(self.opts)
        self.set_all_opts()
        if self.debug>=2: print("Clearing opts to max - max Val:", self.all_options_number_bin)
        if self.debug>=3: print(self.opts)
        self.regions = np.zeros((self.rows, self.cols), dtype=int)
        if self.debug>=1: print("Creating opts")
        if self.debug>=3: print(self.regions)
        self.set_region_map()
        self.set_regions()
        if self.debug>=2: print("setting regions to map - map:", self.ma )
        if self.debug>=3: print(self.opts)
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

