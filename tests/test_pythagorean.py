from python.pythagorean import is_pythagorean


def test_three_four_five() -> None:
    assert is_pythagorean(3, 4, 5)


def test_non_triple() -> None:
    assert not is_pythagorean(3, 4, 6)


def test_negative_input() -> None:
    try:
        is_pythagorean(-3, 4, 5)
    except ValueError:
        pass
    else:
        raise AssertionError("negative input must be rejected")
