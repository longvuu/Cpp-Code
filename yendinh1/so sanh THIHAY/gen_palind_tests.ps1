$base   = "d:\_long\Cpp-Code\yendinh1\so sanh THIHAY"
$testDir = Join-Path $base "tests"

New-Item -ItemType Directory -Force -Path $testDir | Out-Null

# Giới hạn số chữ số: bạn chỉnh tùy đề bài (vd: 1..18)
$minLen = 1
$maxLen = 18

$rand = New-Object System.Random

for ($t = 1; $t -le 300; $t++) {
    $len = $rand.Next($minLen, $maxLen + 1)

    # Tạo số ngẫu nhiên, chữ số đầu tiên != 0
    $first = $rand.Next(1, 10).ToString()
    $s = $first
    for ($i = 2; $i -le $len; $i++) {
        $s += $rand.Next(0, 10).ToString()
    }

    $testId = "{0:000}" -f $t
    $path = Join-Path $testDir "test$testId.inp"
    $s | Set-Content -Encoding UTF8 $path
}

Write-Host "Đã tạo 300 test trong $testDir"