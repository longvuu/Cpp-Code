$ErrorActionPreference = "Stop"

$base    = "d:\_long\Cpp-Code\yendinh1\so sanh THIHAY"
$testDir = Join-Path $base "tests"

# 1. Sinh 300 test nếu chưa có
if (-not (Test-Path $testDir)) {
    New-Item -ItemType Directory -Force -Path $testDir | Out-Null
}

$minLen = 1
$maxLen = 18
$rand = New-Object System.Random

for ($t = 1; $t -le 300; $t++) {
    $testId = "{0:000}" -f $t
    $path = Join-Path $testDir "test$testId.inp"
    if (Test-Path $path) { continue }

    $len = $rand.Next($minLen, $maxLen + 1)
    $first = $rand.Next(1, 10).ToString()
    $s = $first
    for ($i = 2; $i -le $len; $i++) {
        $s += $rand.Next(0, 10).ToString()
    }
    $s | Set-Content -Encoding UTF8 $path
}

# 2. Khai báo các version
$versions = @(
    @{ Name = "th2505172"; Exe = "palind.exe"; Inp = "palind.inp"; Out = "palind.out" },
    @{ Name = "th2505173"; Exe = "PALIND.exe"; Inp = "PALIND.INP"; Out = "PALIND.OUT" },
    @{ Name = "th2505174"; Exe = "PALIND.exe"; Inp = "PALIND.inp"; Out = "PALIND.out" },
    @{ Name = "th2505175"; Exe = "PALIND.exe"; Inp = "PALIND.INP"; Out = "PALIND.OUT" },
    @{ Name = "th2505176"; Exe = "palind.exe"; Inp = "palind.inp"; Out = "palind.out" },
    @{ Name = "th2505177"; Exe = "PALIND.exe"; Inp = "PALIND.inp"; Out = "PALIND.out" }
)

# 3. Lưu kết quả: results[versionName][testId] = answer
$results = @{}
foreach ($v in $versions) {
    $results[$v.Name] = @{}
}

Write-Host "Dang chay 300 test cho tung version..."

for ($t = 1; $t -le 300; $t++) {
    $testId  = "{0:000}" -f $t
    $testFile = Join-Path $testDir "test$testId.inp"
    if (-not (Test-Path $testFile)) { continue }

    foreach ($v in $versions) {
        $dir = Join-Path $base $v.Name
        $inp = Join-Path $dir  $v.Inp
        $out = Join-Path $dir  $v.Out

        Copy-Item $testFile $inp -Force
        Remove-Item $out -ErrorAction SilentlyContinue

        $ans = ""

        try {
            & (Join-Path $dir $v.Exe) | Out-Null
            if (Test-Path $out) {
                $ans = (Get-Content $out -Raw).Trim()
            } else {
                $ans = "[NO_OUT]"
            }
        } catch {
            $ans = "[RTE]"
        }

        $results[$v.Name][$testId] = $ans
    }
}

Write-Host ""
Write-Host "KET QUA SO SANH CAP:"

# 4. So sánh mọi cặp (i < j)
for ($i = 0; $i -lt $versions.Count; $i++) {
    for ($j = $i + 1; $j -lt $versions.Count; $j++) {
        $nameA = $versions[$i].Name
        $nameB = $versions[$j].Name

        $same = 0
        $total = 0

        for ($t = 1; $t -le 300; $t++) {
            $testId  = "{0:000}" -f $t
            if (-not $results[$nameA].ContainsKey($testId)) { continue }
            if (-not $results[$nameB].ContainsKey($testId)) { continue }

            $total++
            if ($results[$nameA][$testId] -eq $results[$nameB][$testId]) {
                $same++
            }
        }

        Write-Host ("{0}-{1}: {2}/{3}" -f $nameA, $nameB, $same, $total)
    }
}